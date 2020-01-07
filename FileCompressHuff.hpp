#pragma once

#include"HuffmanTree.hpp"   //构建哈夫曼树
#include<string>
#include<vector>
#include<assert.h>
using namespace std;



struct CharInfo  //这个结构就是最后要存入到哈夫曼树中的每个结点中的一个自定义类型的内容，
{
	unsigned char _ch;   //字符的类型
	int _count;  //字符在文件中出现的次数
	string _strCode;  //字符的动态不等长编码
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
		return _count == p._count;   //这里只能比较次数，其他另外两个参数不用比较
	}
};

class FileCompressHuff
{
public:
	FileCompressHuff();
	void CompressFile(const string& path);   //压缩函数
	void UNCompressFile(const string& path);  //解压缩函数

private:
	void GenerateHuffmanCode(HuffmanTreeNode<CharInfo>* p);   //HuffmanTreeNode<CharInfo>* p ，  CharInfo：就是哈夫曼树中的权值结点，因为在HuffmanTreeNode中权值本来就是一个模板，所以这里的CharInfo就是权值，只不过权值又是一个自定义的类型
	string GetFilePostFix(string fileName);  //获取文件名，作为下一个函数的传入的参数
	//给压缩文件中写入头部信息的函数
	void WriteHead(FILE* fOut, const string& filePostFix); //最后一个参数就是文件的后缀
	void ReadLine(FILE* fIn, string& strInfo);
private:
	vector<CharInfo> vec;  //保存文件中每个字符，最终编码的vec
};




FileCompressHuff::FileCompressHuff()   //默认构造函数
{
	// 在默认构造函数中，主要做的任务就是，将哈夫曼树中用来记录每个字符信息的数组，初始化好，
	vec.resize(256);   
	for (int i = 0; i < 256; ++i)
	{
		vec[i]._ch = i;  //让每个字符初始化好
		vec[i]._count = 0;  //初始出现的次数都初始化为0
	}
}

void FileCompressHuff::GenerateHuffmanCode(HuffmanTreeNode<CharInfo>* tree)  //获取哈夫曼编码
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
		reverse(strCode.begin(), strCode.end());  //因为是从叶子节点向上获取编码的，所以最后获取到的编码还需要逆序一下
		vec[tree->_weight._ch]._strCode = strCode;  //将最终获取到的编码压入，私有变量vec中，vec中有256个CharInfo类型位置，专门存放哈夫曼树最后求出的字符串编码
	}
}

void FileCompressHuff::CompressFile(const string& path)
{
	//1.统计源文件中每个字符出现的次数、
	FILE* fIn = fopen(path.c_str(),"r");
	if (nullptr == fIn)
	{
		assert(false);    //assert为假则执行
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
		for (int i = 0; i < read_size; ++i)   //记录每个字符出现的次数
		{
			vec[buffer[i]]._count++;
		}
	}
	//2.以字符出现的次数为权值创建哈夫曼树
	HuffmanTree<CharInfo> t(vec, CharInfo());   //构造哈夫曼树，用已经构造好的字符信息数组








	//3.获取每个字符的编码
	GenerateHuffmanCode(t.returnRoot());
	//4.用获取到的字符编码重新改写源文件


	fseek(fIn, 0, SEEK_SET); //文件之前已经打开了，但是已经读到了文件的末尾，所以这里我们需要，重新调整文件读写指针的位置
	FILE* fOut = fopen("2.txt", "wb");  //要来保存压缩后的信息
	if (!fOut)
	{
		assert(false);
		return;
	}

	WriteHead(fOut, path);   //调用写入头信息函数；


	char ch = 0;  //ch用来进行位操作，来存压缩后的字符。A:"100",B"101",C"11",D:"0",ABC假如存在一个位中。那么ch的8个比特位分别就是11010111
	int bitcount = 0;  //因为每个位是一个一个放进去的，bitcount就是用来记录每一个字节，什么时候放满的计数器
	while (true)
	{
		int read_size = fread(buffer, 1, 1024, fIn);  
		if (read_size == 0)
			break;
		//将原文字符根据我们解析出来的字符编码进行替换
		for (int i = 0; i < read_size; ++i)
		{
			string strCode = vec[buffer[i]]._strCode;   //拿出存储到vec中的编码
			for (int j = 0; j < strCode.size(); ++j)
			{
				ch <<= 1;
				if (strCode[j] == '1')
					ch |= 1;
				bitcount++;
				if (bitcount == 8)
				{
					fputc(ch, fOut);     //将整理好的一个字节的字符写到压缩文件中
					bitcount = 0;    //清零
					ch = 0;
				}
			}
		}
	}
	//最后一次ch中可能不够8个比特位
	if (bitcount < 8)
	{
		ch <<= (8 - bitcount);  //最后一个不够8字节的话，就先让，ch左移到最左端，目的就是为了让8个位占满，然后再压入
		fputc(ch, fOut);
	}

	fclose(fOut);
	fclose(fIn);
}

string FileCompressHuff::GetFilePostFix(string fileName)
{
	//D\\xxx\xxx\xxx\2.txt  文件路径类似于这样
	return fileName.substr(fileName.rfind('.'));  //返回截取到的文件类型
}

void FileCompressHuff::WriteHead(FILE* fOut, const string& fileName) //最后一个参数就是文件的后缀
{
	assert(fOut);
	//写文件后缀
	//fwrite(fileName.c_str(), 1, fileName.size(), fOut);
	//写行数
	int lineCount = 0;   //记录行数
	string strChCount;  //记录拼装的字符串
	string strHead;
	strHead += GetFilePostFix(fileName);    //获取源文件的后缀
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

	//最后将拼装好的语句一次性压入
	fwrite(strHead.c_str(), 1, strHead.size(),fOut);

}

void FileCompressHuff::ReadLine(FILE* fIn, string& strInfo)  //从解压缩文件中一次读取一行的函数，注意第二个参数是引用，最后是要传出的
{

	if (fIn == nullptr)
	{
		assert(false);
		return;
	}
	while (!feof(fIn))  //只要文件没有走到末尾
	{
		char ch = fgetc(fIn);  //一次从文件中读取一个字符，
		if (ch == '\n')
			break;

		strInfo += ch;
	}
}

void FileCompressHuff::UNCompressFile(const string& path)  //解压缩主函数
{
	FILE* fIn = fopen(path.c_str(), "rb");   //这里必须以二进制可读的形式打开压缩文件，因为文件分为二进制文件和文本文件
	//文本文件以FF结尾，EOF（-1）标志读到末尾，而我们的压缩文件是二进制文件，如果以文本形式打开，假如有一个二进制是FF，就会使得解压缩要提前结束
	if (fIn == nullptr)
	{
		assert(false);
		return;
	}
	//获取文件后缀
	//接下来的操作需要一行一行的获取,在C++中一行一行获取信息的函数有getline但是这个函数只能对,流,进行操作,
	//而我们使用的fIn不算是流,但是之前的时候,我使用过getline来操作文件,
	//当时打开文件的方式并不是FILE* 使用fopen来打开的 而是使用fstream 这样的文件流来打开的.这里说出来只是为了区分清楚
	//这里我们可以自己封装一个,一次性读一行的函数
	string strFilePostFix;
	ReadLine(fIn, strFilePostFix);
	

	//字符信息总行数
	string strCount;
	ReadLine(fIn, strCount);
	int lineCount = atoi(strCount.c_str());   //字符串转数字

	//字符信息
	//现在往下读的lineCount是字符信息
	for (int i = 0; i < lineCount; ++i)
	{
		string strchCount;
		ReadLine(fIn, strchCount);

		//如果读到的是换行
		if (strchCount.empty())
		{
			strchCount += '\n';
			ReadLine(fIn, strchCount);
		}
		//strchCount = A:5;
		
		int a = atoi(strchCount.c_str() + 2);
		vec[(unsigned char)strchCount[0]]._count = a;  //将字符串截取,并且将截取到的字符串转换成数字,再次存入到vec中,这里的数字就是字符出现的次数
	}

	//还原哈夫曼树
	HuffmanTree<CharInfo>  t;
	t.CreatHuffmanTree(vec, CharInfo(0));

	//拿着压缩数据解压缩
	unsigned char buffer[1024] = { 0 };
	unsigned char ch = 0;
	HuffmanTreeNode<CharInfo>* pCur = t.returnRoot();
	FILE* fOut = fopen("3.txt", "w");
	assert(fOut);

	int filesize = pCur->_weight._count;   //文件总大小就在最上面的结点里面存着
	int countsize = 0;  //要来记录已经解压过的大小

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