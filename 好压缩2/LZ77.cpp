
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
	//如果源文件的大小，小于MIN_MATCH ,也就是三个字节，则不进行压缩

	//获取文件大小
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		std::cout << "打开文件失败" << std::endl;
		return;
	}
	fseek(fIn, 0, SEEK_END);
	ULL filesize = ftell(fIn);   //两个函数搭配获取源文件大小

	//如果源文件大小小于MIN_MATCH，则不进行处理
	if (filesize <= MIN_MATCH)
	{
		std::cout << "文件太小,不压缩" << std::endl;
		return;
	}

	fseek(fIn, 0, SEEK_SET);  //首先移动文件指针到起始位置
	//否则的话则从压缩文件中读取一个缓冲区的数据到窗口中
	//一个缓冲区的大小是64K


	size_t lookAhead = fread(pWin, 1, 2 * WSIZE, fIn);
	USH start = 0;
	USH hashAddr = 0;  //哈希地址
	USH matchHead = 0;  //查找缓冲区中相同字符串的头
	USH curMatchLength = 0;  
	USH curMatchDist = 0;
	//首先将文件的前里昂个字符先单独计算，从第三个开始再进行压缩
	for (USH i = 0; i < MIN_MATCH - 1; ++i)
		ht.HashFunc(hashAddr, pWin[i]);


	//压缩

	//写压缩数据的文件
	FILE* fout = fopen("2.txt", "wb");
	assert(fout);

	//写二进制位图的文件
	FILE* fouts = fopen("8.txt", "wb");
	assert(fouts);

	//与写二进制位图相关的变量
	UCH chFalg = 0;
	UCH bitCount = 0;
	bool isLen = false;


	//lookAhead表示先行缓冲区中剩余字符串的长度，也就是剩余未压缩的字节个数
	while (lookAhead)
	{
		//获取匹配头
		//因为start标记的是当前缓冲区的起始位置，前面已经单独计算了前两个字符，所以这里需要start + 2;
		
		//将当前三个字符插入到哈希表中，并获取匹配链的头
		ht.Insert(hashAddr, pWin[start + 2], start, matchHead);

		//在每次匹配之前将长度和距离进行清空操作
		curMatchDist = 0;
		curMatchLength = 0;
		//2.验证查找缓冲区中是否找到匹配，如果有匹配，则去找最长匹配
		if (matchHead)
		{
			//顺着匹配链找最长的匹配,最终带出<长度，距离>对
			curMatchLength = LongestMatch(matchHead, curMatchDist,start);
		}

		//3.验证是否找到匹配
		if (curMatchLength < MIN_MATCH )
		{
			//在查找缓冲区中没有找到重复的字符串
			//如果没有找到，将start位置的字符直接写入到压缩文件中
			fputc(pWin[start], fout);

			//写当前字符的位图
			WriteFlags(fouts, chFalg, bitCount, false);  

			++start; //查找指针往后移动
			lookAhead--;  //因为已经判断了一个字符，所以文件总大小--
		}
		else
		{
			//找到匹配了，只需要将<长度，距离>对写入到压缩文件中
			
			//写长度
			UCH chLen = curMatchLength - 3;

			fputc(chLen, fout);
			//写距离
			fwrite(&curMatchDist, sizeof(curMatchDist), 1, fout);

			//写位图
			WriteFlags(fouts, chFalg, bitCount, true);
			//将已经匹配的字符串按照三个一组将其插入到哈希表中
			//关于为什么要将已经匹配的字符串再三个三个插入到哈希表中，主要是为了考虑解压缩
			//你想一下解压缩的时候，从前往后走，先压缩，先解压缩，后压缩的还没有解压缩，所以后面继续解压缩的还要依靠前面已经解压缩的数据			

			//更新先行缓冲区中剩余的字节数
			lookAhead -= curMatchLength;

			--curMatchLength;  //当前字符串已经插入
			while (curMatchLength)
			{
				start++;
				ht.Insert(matchHead, pWin[start + 2], start, hashAddr);
				--curMatchLength;
			}
			++start;
		}
		//假如压缩文件的数据大于64K的话，那么就说明我们的64K缓冲区最后肯定是要动起来，
		//数据大于64K的话等到需要滑动的时候，需要舍弃左窗口的32K,再将右窗口的数据搬移到左窗口，再从待压缩文件中，再读取32K作为右窗口的数据
		//这里关于lookAhead <= MIN_LOOKAHEAD是需要再分情况的，其中一种情况是压缩的数据本来就小于MIN_LOOKAHEAD，这时候就不用扩充了，
		//或者很大的数据压缩到了最后的一小部分也不足MIN_LOOKAHEAD也不用扩充了
		if (lookAhead <= MIN_LOOKAHEAD)
			FillWindow(fIn, lookAhead, start);

	}
	//最后一次很有可能不够8位所以需要对不够8位的其他位数进行填充0，然后写入
	if (bitCount > 0 && bitCount < 8)
	{
		chFalg <<= (8 - bitCount);
		fputc(chFalg, fouts);
	}


	//将压缩数据和二进制位图进行合并
	fclose(fouts); //位图文件
	MergeFile(fout, filesize);  //将位图，位图大小，源文件大小一并写入压缩文件
	fclose(fIn);  //源文件
	fclose(fout); //压缩文件


	//既然已经将位图数据全部搬移到压缩文件中了
	//那么就可以把位图文件3.txt删除了
	remove("8.txt");
}

//chFalg该字节的每个比特位是用来区分当前字节是元字符还是长度
//0表示原字符，1表示长度

//bitCount:一个一个用来统计位的计数器

//isLen:用来判断是原字符还是长度
void LZ77::WriteFlags(FILE* fouts, UCH& chFalg, UCH& bitCount, bool isLen)
{
	chFalg <<= 1;
	
	if (isLen)
		chFalg |= 1;


	bitCount++;
	if (bitCount == 8)
	{
		//将位图标记写入到压缩文件
		fputc(chFalg, fouts);
		chFalg = 0;
		bitCount = 0;
	}

}

//匹配：是在查找缓冲区中进行的，而查找缓冲区中可能会找到多个匹配
//最终的输出中需要的是最长的匹配
//注意：可能会遇到环状的链
//注意：匹配实在MAX_DIST范围内进行匹配的，太远的距离则不进行匹配
USH LZ77::LongestMatch(USH matchHead, USH& curMatchDist,USH start)
{
	USH curMatchLen = 0;  //一次匹配的长度
	USH maxMatchLen = 0;
	UCH maxMatchCount = 255;  //最大的匹配次数，最主要就是用来解决环状的链
	USH curMatchStart = 0;   //当前匹配的最长的字符串在查找缓冲区的起始位置

	 
	//先行缓冲区中查找匹配的时候，不能太原即不能超过MAX_DIST
	USH limit = start > MAX_DIST ? start - MAX_DIST : 0;

	do
	{
		//先行缓冲区只的匹配的范围
		UCH* pstart = pWin + start;
		UCH* pend = pstart + MAX_MATCH;

		//查找缓冲区匹配串的起始

		curMatchLen = 0;  //每次匹配的时候都需要把当前匹配长度重新给成0

		UCH* pMstchStart = pWin + matchHead;
		while (pstart < pend && *pstart == *pMstchStart)
		{
			curMatchLen++;
			pstart++;
			pMstchStart++;
		}
		//到这里说明一次匹配结束
		if (curMatchLen > maxMatchLen)
		{
			maxMatchLen = curMatchLen;
			curMatchStart = matchHead;  //记录最长匹配的起始位置，为的就是后面相减就是先行缓冲区中的查找字符和查找缓冲区的相同字符之间的距离
		}
	} while ((matchHead = ht.GetNext(matchHead)) > limit && maxMatchCount--);   //z这里的优先级必须要考虑到位，带括号


	curMatchDist = start - curMatchStart;  //这样可以求出两个之间的距离
	return curMatchLen;  //返回最大匹配长度
}

USH LZHashTable::GetNext(USH matchHead)
{
	return prev[matchHead&HASH_MASK];
}

void LZ77::UNCompressFile(const std::string& strFilePath, const std::string& strFilePath2)
{
	FILE* fInD = fopen(strFilePath.c_str(), "rb");  //打开压缩文件
	if (nullptr == fInD)
	{
		std::cout << "压缩文件打开失败" << std::endl;
		return;
	}

	//操作标记数据指针的文件指针
	FILE* finf = fopen(strFilePath.c_str(), "rb");
	if (nullptr == finf)
	{
		std::cout << "压缩文件打开失败" << std::endl;
		return;
	}

	//获取源文件的大小
	ULL filesize = 0;
	fseek(finf, 0 - sizeof(filesize), SEEK_END);
	fread(&filesize, sizeof(filesize), 1,finf);

	std::cout << filesize << std::endl;

	size_t flagsize = 0;
	//获取标记信息的大小
	fseek(finf, 0-sizeof(filesize) - sizeof(flagsize), SEEK_END);
	fread(&flagsize, sizeof(flagsize), 1, finf);

	//移动finf这个指针，让他指向位图的起始位置

	fseek(finf, 0 - sizeof(flagsize)-sizeof(filesize)-flagsize, SEEK_END);






	FILE* fOut = fopen(strFilePath2.c_str(), "wb");  //打开解压缩文件
	assert(fOut);


	//多设置了一个文件指针，这个文件指针，的主要作用就是用来偏移的，在解压缩文件中偏移之后再利用从压缩文件中独处的距离就可以还原为源文件
	FILE* fR = fopen(strFilePath2.c_str(), "rb");
	assert(fR);

	UCH bitcount = 0;
	UCH chFalg = 0;
	ULL encodeCount = 0;
	while (encodeCount < filesize)  //只要把压缩文件
	{

		if (0 == bitcount)
		{
			chFalg = fgetc(finf);
			bitcount = 8;
		}
		if (chFalg & 0x80)
		{
			//此时表明读入的是距离长度对
			USH matchLen = fgetc(fInD) + 3;
			USH matchDist = 0;
			fread(&matchDist, sizeof(matchDist), 1, fInD);
			
			//清空缓冲区这一步很重要
			//这里的清空缓冲区的目的是目的是因为，你要解压缩肯定就要依靠前面已经解压的文件，但是很有可能操作系统为了节省io操作还没有将已经解压的
			//字符写入文件，那么这个时候就会出现问题，说文件指针读到的字符为空
			fflush(fOut);

			encodeCount += matchLen;  //记录已经解压缩的长度，方便while循环对比

			UCH ch;
			//fR从前文匹配内容
			fseek(fR, 0 - matchDist, SEEK_END);  //从现在正在写的地方往前面偏移0 - matchDist个距离，这里需要注意的就是及时刷新缓冲区
			while (matchLen)
			{
				ch = fgetc(fR);
				fputc(ch, fOut);

				//这一步的刷新很重要，因为可能存在覆盖的那种解压缩
				//这里的刷新和上面的刷新的目的是不一样的，所预防的事情也是不是一个东西
				//这里为什么刷新呢？
				//你想一下压缩的时候，很有可能正在匹配的字符串因为和查找字符串相似的太多，已经将正在匹配的字符串盖过去了，
				//这个时候你还没有将数据写入到文件这个时候就没法再解压缩了，所以这里就要解压一个字符将一个字符写入到文件
				fflush(fOut);


				matchLen--;
			}
		}
		else
		{
			//这样的话说明读入的是原字符
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
	FILE* finf = fopen("8.txt", "rb");  //打开位图文件
	size_t flagSize = 0;  //记录位图大小的变量
	UCH* pReadbuff = new UCH[1024];
	while (true)
	{
		size_t rdSize = fread(pReadbuff, 1, 1024, finf);
		if (rdSize == 0)
			break;

		fwrite(pReadbuff, 1, rdSize, fout);
		flagSize += rdSize;  //累加记录
	}
	//再将位图大小写入到压缩文件
	fwrite(&flagSize, sizeof(flagSize), 1, fout);

	//再写源文件大小，之前已经计算出来了
	fwrite(&filesize, sizeof(filesize), 1, fout);

	delete[] pReadbuff;
	fclose(finf);
}


void LZ77::FillWindow(FILE* fIn, size_t& lookAhead, USH& start)
{
	//这个判断主要就是为了判断是否真的需要扩充缓冲区
	//只有start出现在右窗的时候才说明是真的需要扩容，
	if (start >= WSIZE)
	{
		start -= WSIZE;

		//1.将右窗中的数据搬移到左窗
		memcpy(pWin, pWin + WSIZE, WSIZE);

		//2.更新哈希表
		ht.update();

		//3.向右窗中补充数据
		if (!feof(fIn))
			lookAhead += fread(pWin + WSIZE, 1, WSIZE, fIn);

	}
}


