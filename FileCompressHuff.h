#pragma once

#include"HuffmanTree.hpp"   //������������
#include<string>
#include<vector>
#include<assert.h>
using namespace std;



struct CharInfo  //����ṹ�������Ҫ���뵽���������е�ÿ������е�һ���Զ������͵����ݣ�
{
	char _ch;   //�ַ�������
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
	void CompressFile(const string& path);
	void UNCompressFile(const string& path);

private:
	void GenerateHuffmanCode(HuffmanTreeNode<CharInfo>* p);
private:
	vector<CharInfo> vec;
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
		reverse(strCode.begin(), strCode.end());
		cout << strCode << endl;
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
	//2.���ַ����ֵĴ���ΪȨֵ������������
	HuffmanTree<CharInfo> t(vec, CharInfo());   //����������������Ѿ�����õ��ַ���Ϣ����








	//3.��ȡÿ���ַ��ı���
	GenerateHuffmanCode(t.returnRoot());
	//4.�û�ȡ�����ַ��������¸�дԴ�ļ�



	fclose(fIn);
}

void test()
{
	FileCompressHuff p;
	p.CompressFile("1.txt");
}