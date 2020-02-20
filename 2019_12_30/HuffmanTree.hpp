//什么是哈夫曼树：带权路径长度最短的一棵二叉树---权值越大，越靠近根节点
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
	HuffmanTreeNode<T>* _left;   //左孩子
	HuffmanTreeNode<T>* _right;  //右孩子
	HuffmanTreeNode<T>* _parent;  //双亲结点
	T _weight;  //权值
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
	HuffmanTree()   //默认构造函数
		:_root(nullptr)
	{}
	HuffmanTree(const vector<T>& p,const T& invalid)   //invalid的意思就是无效的权值，就是权值无效的话，则就不用创建结点
	{
		CreatHuffmanTree(p,invalid);
	}
	~HuffmanTree()
	{
		_destoryHuffmanTree(_root);
	}
	void CreatHuffmanTree(const vector<T>& weight,const T& invalid)
	{
		priority_queue<Node*,vector<Node*>,Less<T> > p;  //小堆
		//1.构建森林
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
