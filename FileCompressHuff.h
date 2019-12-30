#pragma once

#include"HuffmanTree.hpp"   //构建哈夫曼树
#include<string>
#include<vector>
#include<assert.h>
using namespace std;



struct CharInfo  //这个结构就是最后要存入到哈夫曼树中的每个结点中的一个自定义类型的内容，
{
	char _ch;   //字符的类型
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
	void CompressFile(const string& path);
	void UNCompressFile(const string& path);

private:
	void GenerateHuffmanCode(HuffmanTreeNode<CharInfo>* p);
private:
	vector<CharInfo> vec;
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
		reverse(strCode.begin(), strCode.end());
		cout << strCode << endl;
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
	char buffer[1024];
	while (1)
	{
		int read_size = fread(buffer, 1, 1024, fIn);
		if (read_size == 0)
		{
			break;
		}
		for (int i = 0; i < read_size; ++i)
		{
			vec[buffer[i]]._count++;
		}
	}
	//2.以字符出现的次数为权值创建哈夫曼树
	HuffmanTree<CharInfo> t(vec, CharInfo());   //构造哈夫曼树，用已经构造好的字符信息数组








	//3.获取每个字符的编码
	GenerateHuffmanCode(t.returnRoot());
	//4.用获取到的字符编码重新改写源文件



	fclose(fIn);
}

void test()
{
	FileCompressHuff p;
	p.CompressFile("1.txt");
}