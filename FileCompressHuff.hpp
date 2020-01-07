#pragma once

#include"HuffmanTree.hpp"   //������������
#include<string>
#include<vector>
#include<assert.h>
using namespace std;



struct CharInfo  //����ṹ�������Ҫ���뵽���������е�ÿ������е�һ���Զ������͵����ݣ�
{
	unsigned char _ch;   //�ַ�������
	int _count;  //�ַ����ļ��г��ֵĴ���
	string _strCode;  //�ַ��Ķ�̬���ȳ�����
	CharInfo(int count = 0)
	{
		_count = count;
	}
	CharInfo operator+(const CharInfo& p)
	{
		return CharInfo(_count + p._count);
	}
	bool operator>(const CharInfo& p)
	{
		return this->_count > p._count;
	}
	bool operator==(const CharInfo& p)const
	{
		return _count == p._count;   //����ֻ�ܱȽϴ������������������������ñȽ�
	}
};

class FileCompressHuff
{
public:
	FileCompressHuff();
	void CompressFile(const string& path);   //ѹ������
	void UNCompressFile(const string& path);  //��ѹ������

private:
	void GenerateHuffmanCode(HuffmanTreeNode<CharInfo>* p);   //HuffmanTreeNode<CharInfo>* p ��  CharInfo�����ǹ��������е�Ȩֵ��㣬��Ϊ��HuffmanTreeNode��Ȩֵ��������һ��ģ�壬���������CharInfo����Ȩֵ��ֻ����Ȩֵ����һ���Զ��������
	string GetFilePostFix(string fileName);  //��ȡ�ļ�������Ϊ��һ�������Ĵ���Ĳ���
	//��ѹ���ļ���д��ͷ����Ϣ�ĺ���
	void WriteHead(FILE* fOut, const string& filePostFix); //���һ�����������ļ��ĺ�׺
	void ReadLine(FILE* fIn, string& strInfo);
private:
	vector<CharInfo> vec;  //�����ļ���ÿ���ַ������ձ����vec
};




FileCompressHuff::FileCompressHuff()   //Ĭ�Ϲ��캯��
{
	// ��Ĭ�Ϲ��캯���У���Ҫ����������ǣ�������������������¼ÿ���ַ���Ϣ�����飬��ʼ���ã�
	vec.resize(256);   
	for (int i = 0; i < 256; ++i)
	{
		vec[i]._ch = i;  //��ÿ���ַ���ʼ����
		vec[i]._count = 0;  //��ʼ���ֵĴ�������ʼ��Ϊ0
	}
}

void FileCompressHuff::GenerateHuffmanCode(HuffmanTreeNode<CharInfo>* tree)  //��ȡ����������
{
	if (tree == nullptr)
		return;
	GenerateHuffmanCode(tree->_left);
	GenerateHuffmanCode(tree->_right);
	if (tree->_left == nullptr && tree->_right == nullptr)
	{
		string strCode;
		HuffmanTreeNode<CharInfo>* pCur = tree;
		HuffmanTreeNode<CharInfo>* pParent = pCur->_parent;
		while (pParent)
		{
			if (pCur == pParent->_left)
			{
				strCode += '0';
			}
			else
				strCode += '1';
			pCur = pParent;
			pParent = pCur->_parent;
		}
		reverse(strCode.begin(), strCode.end());  //��Ϊ�Ǵ�Ҷ�ӽڵ����ϻ�ȡ����ģ���������ȡ���ı��뻹��Ҫ����һ��
		vec[tree->_weight._ch]._strCode = strCode;  //�����ջ�ȡ���ı���ѹ�룬˽�б���vec�У�vec����256��CharInfo����λ�ã�ר�Ŵ�Ź����������������ַ�������
	}
}

void FileCompressHuff::CompressFile(const string& path)
{
	//1.ͳ��Դ�ļ���ÿ���ַ����ֵĴ�����
	FILE* fIn = fopen(path.c_str(),"r");
	if (nullptr == fIn)
	{
		assert(false);    //assertΪ����ִ��
		return;
	}
	unsigned char buffer[1024];
	while (1)
	{
		int read_size = fread(buffer, 1, 1024, fIn);
		if (read_size == 0)
		{
			break;
		}
		for (int i = 0; i < read_size; ++i)   //��¼ÿ���ַ����ֵĴ���
		{
			vec[buffer[i]]._count++;
		}
	}
	//2.���ַ����ֵĴ���ΪȨֵ������������
	HuffmanTree<CharInfo> t(vec, CharInfo());   //����������������Ѿ�����õ��ַ���Ϣ����








	//3.��ȡÿ���ַ��ı���
	GenerateHuffmanCode(t.returnRoot());
	//4.�û�ȡ�����ַ��������¸�дԴ�ļ�


	fseek(fIn, 0, SEEK_SET); //�ļ�֮ǰ�Ѿ����ˣ������Ѿ��������ļ���ĩβ����������������Ҫ�����µ����ļ���дָ���λ��
	FILE* fOut = fopen("2.txt", "wb");  //Ҫ������ѹ�������Ϣ
	if (!fOut)
	{
		assert(false);
		return;
	}

	WriteHead(fOut, path);   //����д��ͷ��Ϣ������


	char ch = 0;  //ch��������λ����������ѹ������ַ���A:"100",B"101",C"11",D:"0",ABC�������һ��λ�С���ôch��8������λ�ֱ����11010111
	int bitcount = 0;  //��Ϊÿ��λ��һ��һ���Ž�ȥ�ģ�bitcount����������¼ÿһ���ֽڣ�ʲôʱ������ļ�����
	while (true)
	{
		int read_size = fread(buffer, 1, 1024, fIn);  
		if (read_size == 0)
			break;
		//��ԭ���ַ��������ǽ����������ַ���������滻
		for (int i = 0; i < read_size; ++i)
		{
			string strCode = vec[buffer[i]]._strCode;   //�ó��洢��vec�еı���
			for (int j = 0; j < strCode.size(); ++j)
			{
				ch <<= 1;
				if (strCode[j] == '1')
					ch |= 1;
				bitcount++;
				if (bitcount == 8)
				{
					fputc(ch, fOut);     //������õ�һ���ֽڵ��ַ�д��ѹ���ļ���
					bitcount = 0;    //����
					ch = 0;
				}
			}
		}
	}
	//���һ��ch�п��ܲ���8������λ
	if (bitcount < 8)
	{
		ch <<= (8 - bitcount);  //���һ������8�ֽڵĻ��������ã�ch���Ƶ�����ˣ�Ŀ�ľ���Ϊ����8��λռ����Ȼ����ѹ��
		fputc(ch, fOut);
	}

	fclose(fOut);
	fclose(fIn);
}

string FileCompressHuff::GetFilePostFix(string fileName)
{
	//D\\xxx\xxx\xxx\2.txt  �ļ�·������������
	return fileName.substr(fileName.rfind('.'));  //���ؽ�ȡ�����ļ�����
}

void FileCompressHuff::WriteHead(FILE* fOut, const string& fileName) //���һ�����������ļ��ĺ�׺
{
	assert(fOut);
	//д�ļ���׺
	//fwrite(fileName.c_str(), 1, fileName.size(), fOut);
	//д����
	int lineCount = 0;   //��¼����
	string strChCount;  //��¼ƴװ���ַ���
	string strHead;
	strHead += GetFilePostFix(fileName);    //��ȡԴ�ļ��ĺ�׺
	strHead += '\n';
	for (int i = 0; i < 256; ++i)
	{
		if (vec[i]._count)
		{
			lineCount++;
			strChCount += vec[i]._ch;
			strChCount += ':';
			strChCount += to_string(vec[i]._count);
			strChCount += '\n';
		}
	}
	string s = to_string(lineCount);
	strHead += s;
	strHead += '\n';
	strHead += strChCount;

	//���ƴװ�õ����һ����ѹ��
	fwrite(strHead.c_str(), 1, strHead.size(),fOut);

}

void FileCompressHuff::ReadLine(FILE* fIn, string& strInfo)  //�ӽ�ѹ���ļ���һ�ζ�ȡһ�еĺ�����ע��ڶ������������ã������Ҫ������
{

	if (fIn == nullptr)
	{
		assert(false);
		return;
	}
	while (!feof(fIn))  //ֻҪ�ļ�û���ߵ�ĩβ
	{
		char ch = fgetc(fIn);  //һ�δ��ļ��ж�ȡһ���ַ���
		if (ch == '\n')
			break;

		strInfo += ch;
	}
}

void FileCompressHuff::UNCompressFile(const string& path)  //��ѹ��������
{
	FILE* fIn = fopen(path.c_str(), "rb");   //��������Զ����ƿɶ�����ʽ��ѹ���ļ�����Ϊ�ļ���Ϊ�������ļ����ı��ļ�
	//�ı��ļ���FF��β��EOF��-1����־����ĩβ�������ǵ�ѹ���ļ��Ƕ������ļ���������ı���ʽ�򿪣�������һ����������FF���ͻ�ʹ�ý�ѹ��Ҫ��ǰ����
	if (fIn == nullptr)
	{
		assert(false);
		return;
	}
	//��ȡ�ļ���׺
	//�������Ĳ�����Ҫһ��һ�еĻ�ȡ,��C++��һ��һ�л�ȡ��Ϣ�ĺ�����getline�����������ֻ�ܶ�,��,���в���,
	//������ʹ�õ�fIn��������,����֮ǰ��ʱ��,��ʹ�ù�getline�������ļ�,
	//��ʱ���ļ��ķ�ʽ������FILE* ʹ��fopen���򿪵� ����ʹ��fstream �������ļ������򿪵�.����˵����ֻ��Ϊ���������
	//�������ǿ����Լ���װһ��,һ���Զ�һ�еĺ���
	string strFilePostFix;
	ReadLine(fIn, strFilePostFix);
	

	//�ַ���Ϣ������
	string strCount;
	ReadLine(fIn, strCount);
	int lineCount = atoi(strCount.c_str());   //�ַ���ת����

	//�ַ���Ϣ
	//�������¶���lineCount���ַ���Ϣ
	for (int i = 0; i < lineCount; ++i)
	{
		string strchCount;
		ReadLine(fIn, strchCount);

		//����������ǻ���
		if (strchCount.empty())
		{
			strchCount += '\n';
			ReadLine(fIn, strchCount);
		}
		//strchCount = A:5;
		
		int a = atoi(strchCount.c_str() + 2);
		vec[(unsigned char)strchCount[0]]._count = a;  //���ַ�����ȡ,���ҽ���ȡ�����ַ���ת��������,�ٴδ��뵽vec��,��������־����ַ����ֵĴ���
	}

	//��ԭ��������
	HuffmanTree<CharInfo>  t;
	t.CreatHuffmanTree(vec, CharInfo(0));

	//����ѹ�����ݽ�ѹ��
	unsigned char buffer[1024] = { 0 };
	unsigned char ch = 0;
	HuffmanTreeNode<CharInfo>* pCur = t.returnRoot();
	FILE* fOut = fopen("3.txt", "w");
	assert(fOut);

	int filesize = pCur->_weight._count;   //�ļ��ܴ�С����������Ľ���������
	int countsize = 0;  //Ҫ����¼�Ѿ���ѹ���Ĵ�С

	while (true)
	{
		size_t read_size = fread(buffer, 1, 1024, fIn);
		if (read_size == 0)
			break;
		for (size_t i= 0; i < read_size; ++i)
		{
			ch = buffer[i];
			for (size_t j = 0; j < 8; ++j)
			{
				if (ch & 0x80)
					pCur = pCur->_right;
				else
					pCur = pCur->_left;
				
				ch <<= 1;
				if (pCur->_left == nullptr && pCur->_right == nullptr)
				{
					countsize++;
					fputc(pCur->_weight._ch, fOut);
					if (countsize == filesize)
						break;
					pCur = t.returnRoot();
				}
			}
		}

	}
	fclose(fIn);
	fclose(fOut);
}


void test()
{
	FileCompressHuff p;
	p.CompressFile("1.txt");
	p.UNCompressFile("2.txt");
}