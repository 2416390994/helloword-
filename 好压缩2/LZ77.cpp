
#pragma once
#include<assert.h>
#include<iostream>
#include "LZ77.h"

const USH MIN_LOOKAHEAD = MAX_MATCH + MIN_MATCH + 1;
const USH MAX_DIST = WSIZE - MIN_LOOKAHEAD;

LZ77::LZ77()
:pWin(new UCH[WSIZE * 2])
, ht(WSIZE)
{

}
LZ77::~LZ77()
{
	delete[] pWin;
	pWin = nullptr;
}

void LZ77::CompressFile(const std::string& strFilePath)
{
	//���Դ�ļ��Ĵ�С��С��MIN_MATCH ,Ҳ���������ֽڣ��򲻽���ѹ��

	//��ȡ�ļ���С
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		std::cout << "���ļ�ʧ��" << std::endl;
		return;
	}
	fseek(fIn, 0, SEEK_END);
	ULL filesize = ftell(fIn);   //�������������ȡԴ�ļ���С

	//���Դ�ļ���СС��MIN_MATCH���򲻽��д���
	if (filesize <= MIN_MATCH)
	{
		std::cout << "�ļ�̫С,��ѹ��" << std::endl;
		return;
	}

	fseek(fIn, 0, SEEK_SET);  //�����ƶ��ļ�ָ�뵽��ʼλ��
	//����Ļ����ѹ���ļ��ж�ȡһ�������������ݵ�������
	//һ���������Ĵ�С��64K


	size_t lookAhead = fread(pWin, 1, 2 * WSIZE, fIn);
	USH start = 0;
	USH hashAddr = 0;  //��ϣ��ַ
	USH matchHead = 0;  //���һ���������ͬ�ַ�����ͷ
	USH curMatchLength = 0;  
	USH curMatchDist = 0;
	//���Ƚ��ļ���ǰ�ﰺ���ַ��ȵ������㣬�ӵ�������ʼ�ٽ���ѹ��
	for (USH i = 0; i < MIN_MATCH - 1; ++i)
		ht.HashFunc(hashAddr, pWin[i]);


	//ѹ��

	//дѹ�����ݵ��ļ�
	FILE* fout = fopen("2.txt", "wb");
	assert(fout);

	//д������λͼ���ļ�
	FILE* fouts = fopen("8.txt", "wb");
	assert(fouts);

	//��д������λͼ��صı���
	UCH chFalg = 0;
	UCH bitCount = 0;
	bool isLen = false;


	//lookAhead��ʾ���л�������ʣ���ַ����ĳ��ȣ�Ҳ����ʣ��δѹ�����ֽڸ���
	while (lookAhead)
	{
		//��ȡƥ��ͷ
		//��Ϊstart��ǵ��ǵ�ǰ����������ʼλ�ã�ǰ���Ѿ�����������ǰ�����ַ�������������Ҫstart + 2;
		
		//����ǰ�����ַ����뵽��ϣ���У�����ȡƥ������ͷ
		ht.Insert(hashAddr, pWin[start + 2], start, matchHead);

		//��ÿ��ƥ��֮ǰ�����Ⱥ;��������ղ���
		curMatchDist = 0;
		curMatchLength = 0;
		//2.��֤���һ��������Ƿ��ҵ�ƥ�䣬�����ƥ�䣬��ȥ���ƥ��
		if (matchHead)
		{
			//˳��ƥ���������ƥ��,���մ���<���ȣ�����>��
			curMatchLength = LongestMatch(matchHead, curMatchDist,start);
		}

		//3.��֤�Ƿ��ҵ�ƥ��
		if (curMatchLength < MIN_MATCH )
		{
			//�ڲ��һ�������û���ҵ��ظ����ַ���
			//���û���ҵ�����startλ�õ��ַ�ֱ��д�뵽ѹ���ļ���
			fputc(pWin[start], fout);

			//д��ǰ�ַ���λͼ
			WriteFlags(fouts, chFalg, bitCount, false);  

			++start; //����ָ�������ƶ�
			lookAhead--;  //��Ϊ�Ѿ��ж���һ���ַ��������ļ��ܴ�С--
		}
		else
		{
			//�ҵ�ƥ���ˣ�ֻ��Ҫ��<���ȣ�����>��д�뵽ѹ���ļ���
			
			//д����
			UCH chLen = curMatchLength - 3;

			fputc(chLen, fout);
			//д����
			fwrite(&curMatchDist, sizeof(curMatchDist), 1, fout);

			//дλͼ
			WriteFlags(fouts, chFalg, bitCount, true);
			//���Ѿ�ƥ����ַ�����������һ�齫����뵽��ϣ����
			//����ΪʲôҪ���Ѿ�ƥ����ַ����������������뵽��ϣ���У���Ҫ��Ϊ�˿��ǽ�ѹ��
			//����һ�½�ѹ����ʱ�򣬴�ǰ�����ߣ���ѹ�����Ƚ�ѹ������ѹ���Ļ�û�н�ѹ�������Ժ��������ѹ���Ļ�Ҫ����ǰ���Ѿ���ѹ��������			

			//�������л�������ʣ����ֽ���
			lookAhead -= curMatchLength;

			--curMatchLength;  //��ǰ�ַ����Ѿ�����
			while (curMatchLength)
			{
				start++;
				ht.Insert(matchHead, pWin[start + 2], start, hashAddr);
				--curMatchLength;
			}
			++start;
		}
		//����ѹ���ļ������ݴ���64K�Ļ�����ô��˵�����ǵ�64K���������϶���Ҫ��������
		//���ݴ���64K�Ļ��ȵ���Ҫ������ʱ����Ҫ�����󴰿ڵ�32K,�ٽ��Ҵ��ڵ����ݰ��Ƶ��󴰿ڣ��ٴӴ�ѹ���ļ��У��ٶ�ȡ32K��Ϊ�Ҵ��ڵ�����
		//�������lookAhead <= MIN_LOOKAHEAD����Ҫ�ٷ�����ģ�����һ�������ѹ�������ݱ�����С��MIN_LOOKAHEAD����ʱ��Ͳ��������ˣ�
		//���ߺܴ������ѹ����������һС����Ҳ����MIN_LOOKAHEADҲ����������
		if (lookAhead <= MIN_LOOKAHEAD)
			FillWindow(fIn, lookAhead, start);

	}
	//���һ�κ��п��ܲ���8λ������Ҫ�Բ���8λ������λ���������0��Ȼ��д��
	if (bitCount > 0 && bitCount < 8)
	{
		chFalg <<= (8 - bitCount);
		fputc(chFalg, fouts);
	}


	//��ѹ�����ݺͶ�����λͼ���кϲ�
	fclose(fouts); //λͼ�ļ�
	MergeFile(fout, filesize);  //��λͼ��λͼ��С��Դ�ļ���Сһ��д��ѹ���ļ�
	fclose(fIn);  //Դ�ļ�
	fclose(fout); //ѹ���ļ�


	//��Ȼ�Ѿ���λͼ����ȫ�����Ƶ�ѹ���ļ�����
	//��ô�Ϳ��԰�λͼ�ļ�3.txtɾ����
	remove("8.txt");
}

//chFalg���ֽڵ�ÿ������λ���������ֵ�ǰ�ֽ���Ԫ�ַ����ǳ���
//0��ʾԭ�ַ���1��ʾ����

//bitCount:һ��һ������ͳ��λ�ļ�����

//isLen:�����ж���ԭ�ַ����ǳ���
void LZ77::WriteFlags(FILE* fouts, UCH& chFalg, UCH& bitCount, bool isLen)
{
	chFalg <<= 1;
	
	if (isLen)
		chFalg |= 1;


	bitCount++;
	if (bitCount == 8)
	{
		//��λͼ���д�뵽ѹ���ļ�
		fputc(chFalg, fouts);
		chFalg = 0;
		bitCount = 0;
	}

}

//ƥ�䣺���ڲ��һ������н��еģ������һ������п��ܻ��ҵ����ƥ��
//���յ��������Ҫ�������ƥ��
//ע�⣺���ܻ�������״����
//ע�⣺ƥ��ʵ��MAX_DIST��Χ�ڽ���ƥ��ģ�̫Զ�ľ����򲻽���ƥ��
USH LZ77::LongestMatch(USH matchHead, USH& curMatchDist,USH start)
{
	USH curMatchLen = 0;  //һ��ƥ��ĳ���
	USH maxMatchLen = 0;
	UCH maxMatchCount = 255;  //����ƥ�����������Ҫ�������������״����
	USH curMatchStart = 0;   //��ǰƥ�������ַ����ڲ��һ���������ʼλ��

	 
	//���л������в���ƥ���ʱ�򣬲���̫ԭ�����ܳ���MAX_DIST
	USH limit = start > MAX_DIST ? start - MAX_DIST : 0;

	do
	{
		//���л�����ֻ��ƥ��ķ�Χ
		UCH* pstart = pWin + start;
		UCH* pend = pstart + MAX_MATCH;

		//���һ�����ƥ�䴮����ʼ

		curMatchLen = 0;  //ÿ��ƥ���ʱ����Ҫ�ѵ�ǰƥ�䳤�����¸���0

		UCH* pMstchStart = pWin + matchHead;
		while (pstart < pend && *pstart == *pMstchStart)
		{
			curMatchLen++;
			pstart++;
			pMstchStart++;
		}
		//������˵��һ��ƥ�����
		if (curMatchLen > maxMatchLen)
		{
			maxMatchLen = curMatchLen;
			curMatchStart = matchHead;  //��¼�ƥ�����ʼλ�ã�Ϊ�ľ��Ǻ�������������л������еĲ����ַ��Ͳ��һ���������ͬ�ַ�֮��ľ���
		}
	} while ((matchHead = ht.GetNext(matchHead)) > limit && maxMatchCount--);   //z��������ȼ�����Ҫ���ǵ�λ��������


	curMatchDist = start - curMatchStart;  //���������������֮��ľ���
	return curMatchLen;  //�������ƥ�䳤��
}

USH LZHashTable::GetNext(USH matchHead)
{
	return prev[matchHead&HASH_MASK];
}

void LZ77::UNCompressFile(const std::string& strFilePath, const std::string& strFilePath2)
{
	FILE* fInD = fopen(strFilePath.c_str(), "rb");  //��ѹ���ļ�
	if (nullptr == fInD)
	{
		std::cout << "ѹ���ļ���ʧ��" << std::endl;
		return;
	}

	//�����������ָ����ļ�ָ��
	FILE* finf = fopen(strFilePath.c_str(), "rb");
	if (nullptr == finf)
	{
		std::cout << "ѹ���ļ���ʧ��" << std::endl;
		return;
	}

	//��ȡԴ�ļ��Ĵ�С
	ULL filesize = 0;
	fseek(finf, 0 - sizeof(filesize), SEEK_END);
	fread(&filesize, sizeof(filesize), 1,finf);

	std::cout << filesize << std::endl;

	size_t flagsize = 0;
	//��ȡ�����Ϣ�Ĵ�С
	fseek(finf, 0-sizeof(filesize) - sizeof(flagsize), SEEK_END);
	fread(&flagsize, sizeof(flagsize), 1, finf);

	//�ƶ�finf���ָ�룬����ָ��λͼ����ʼλ��

	fseek(finf, 0 - sizeof(flagsize)-sizeof(filesize)-flagsize, SEEK_END);






	FILE* fOut = fopen(strFilePath2.c_str(), "wb");  //�򿪽�ѹ���ļ�
	assert(fOut);


	//��������һ���ļ�ָ�룬����ļ�ָ�룬����Ҫ���þ�������ƫ�Ƶģ��ڽ�ѹ���ļ���ƫ��֮�������ô�ѹ���ļ��ж����ľ���Ϳ��Ի�ԭΪԴ�ļ�
	FILE* fR = fopen(strFilePath2.c_str(), "rb");
	assert(fR);

	UCH bitcount = 0;
	UCH chFalg = 0;
	ULL encodeCount = 0;
	while (encodeCount < filesize)  //ֻҪ��ѹ���ļ�
	{

		if (0 == bitcount)
		{
			chFalg = fgetc(finf);
			bitcount = 8;
		}
		if (chFalg & 0x80)
		{
			//��ʱ����������Ǿ��볤�ȶ�
			USH matchLen = fgetc(fInD) + 3;
			USH matchDist = 0;
			fread(&matchDist, sizeof(matchDist), 1, fInD);
			
			//��ջ�������һ������Ҫ
			//�������ջ�������Ŀ����Ŀ������Ϊ����Ҫ��ѹ���϶���Ҫ����ǰ���Ѿ���ѹ���ļ������Ǻ��п��ܲ���ϵͳΪ�˽�ʡio������û�н��Ѿ���ѹ��
			//�ַ�д���ļ�����ô���ʱ��ͻ�������⣬˵�ļ�ָ��������ַ�Ϊ��
			fflush(fOut);

			encodeCount += matchLen;  //��¼�Ѿ���ѹ���ĳ��ȣ�����whileѭ���Ա�

			UCH ch;
			//fR��ǰ��ƥ������
			fseek(fR, 0 - matchDist, SEEK_END);  //����������д�ĵط���ǰ��ƫ��0 - matchDist�����룬������Ҫע��ľ��Ǽ�ʱˢ�»�����
			while (matchLen)
			{
				ch = fgetc(fR);
				fputc(ch, fOut);

				//��һ����ˢ�º���Ҫ����Ϊ���ܴ��ڸ��ǵ����ֽ�ѹ��
				//�����ˢ�º������ˢ�µ�Ŀ���ǲ�һ���ģ���Ԥ��������Ҳ�ǲ���һ������
				//����Ϊʲôˢ���أ�
				//����һ��ѹ����ʱ�򣬺��п�������ƥ����ַ�����Ϊ�Ͳ����ַ������Ƶ�̫�࣬�Ѿ�������ƥ����ַ����ǹ�ȥ�ˣ�
				//���ʱ���㻹û�н�����д�뵽�ļ����ʱ���û���ٽ�ѹ���ˣ����������Ҫ��ѹһ���ַ���һ���ַ�д�뵽�ļ�
				fflush(fOut);


				matchLen--;
			}
		}
		else
		{
			//�����Ļ�˵���������ԭ�ַ�
			UCH ch = fgetc(fInD);
			fputc(ch, fOut);
			encodeCount++;
		}

		chFalg <<= 1;
		bitcount--;
	}

	fclose(fOut);
	fclose(fInD);
	fclose(finf);
	fclose(fR);
}


void LZ77::MergeFile(FILE* fout, ULL filesize)
{
	FILE* finf = fopen("8.txt", "rb");  //��λͼ�ļ�
	size_t flagSize = 0;  //��¼λͼ��С�ı���
	UCH* pReadbuff = new UCH[1024];
	while (true)
	{
		size_t rdSize = fread(pReadbuff, 1, 1024, finf);
		if (rdSize == 0)
			break;

		fwrite(pReadbuff, 1, rdSize, fout);
		flagSize += rdSize;  //�ۼӼ�¼
	}
	//�ٽ�λͼ��Сд�뵽ѹ���ļ�
	fwrite(&flagSize, sizeof(flagSize), 1, fout);

	//��дԴ�ļ���С��֮ǰ�Ѿ����������
	fwrite(&filesize, sizeof(filesize), 1, fout);

	delete[] pReadbuff;
	fclose(finf);
}


void LZ77::FillWindow(FILE* fIn, size_t& lookAhead, USH& start)
{
	//����ж���Ҫ����Ϊ���ж��Ƿ������Ҫ���仺����
	//ֻ��start�������Ҵ���ʱ���˵���������Ҫ���ݣ�
	if (start >= WSIZE)
	{
		start -= WSIZE;

		//1.���Ҵ��е����ݰ��Ƶ���
		memcpy(pWin, pWin + WSIZE, WSIZE);

		//2.���¹�ϣ��
		ht.update();

		//3.���Ҵ��в�������
		if (!feof(fIn))
			lookAhead += fread(pWin + WSIZE, 1, WSIZE, fIn);

	}
}


