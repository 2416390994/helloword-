//ʲô�ǹ�����������Ȩ·��������̵�һ�ö�����---ȨֵԽ��Խ�������ڵ�
#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<class T>
struct HuffmanTreeNode
{
	HuffmanTreeNode(const T& weight = T())
	:_left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _weight(weight)
	{}
	HuffmanTreeNode<T>* _left;   //����
	HuffmanTreeNode<T>* _right;  //�Һ���
	HuffmanTreeNode<T>* _parent;  //˫�׽��
	T _weight;  //Ȩֵ
};

template<class T>
class Less
{
	typedef HuffmanTreeNode<T> Node;
public:
	bool operator()(Node* left, Node* right)
	{
		return left->_weight > right->_weight;
	}
};

template<class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> Node;
public:
	HuffmanTree()   //Ĭ�Ϲ��캯��
		:_root(nullptr)
	{}
	HuffmanTree(const vector<T>& p,const T& invalid)   //invalid����˼������Ч��Ȩֵ������Ȩֵ��Ч�Ļ�����Ͳ��ô������
	{
		CreatHuffmanTree(p,invalid);
	}
	~HuffmanTree()
	{
		_destoryHuffmanTree(_root);
	}
	void CreatHuffmanTree(const vector<T>& weight,const T& invalid)
	{
		priority_queue<Node*,vector<Node*>,Less<T> > p;  //С��
		//1.����ɭ��
		for (auto e : weight )
		{
			if (e == invalid)
				continue;
				p.push(new Node(e));
		}
		//cout << p.size() << endl;

		while (p.size() > 1)
		{
			Node* left = p.top();
			p.pop();
			Node* right = p.top();
			p.pop();

			Node* pParent = new Node(left->_weight + right->_weight);
			pParent->_left = left;
			pParent->_right = right;
			left->_parent = pParent;
			right->_parent = pParent;
			p.push(pParent);
		}
		_root = p.top();
	}
	Node* returnRoot()
	{
		return _root;
	}
	
	void _destoryHuffmanTree(Node*& tree)
	{
		if (tree)
		{
			_destoryHuffmanTree(tree->_left);
			_destoryHuffmanTree(tree->_right);
			delete tree;
			tree = nullptr;
		}
	}

private:
	Node* _root;
};
