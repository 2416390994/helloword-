#include<iostream>
#include<vector>
#include<list>
using namespace std;
namespace N1
{
	//list��ͷ����˫������
	template<class T>    //�����T�Ǳ���������
	struct ListNode   //�ڵ�ṹ
	{	
		ListNode<T>* _next;
		ListNode<T>* _prv;
		T _data;
		ListNode(const T& data = T())
			:_next(nullptr)
			, _prv(nullptr)
			, _data(data)
		{}
	};
	//list�����������ڵ����͵�ָ����з�װ
	template<class T>   //�����T�����Ҳ�Ǳ���������
	struct list_iterator
	{
		typedef ListNode<T> Node;  //���������һ����������Node,<T>������ǽڵ����������ݵ�����
		list_iterator(Node* pCur)    //ֻ�ṩ���вι��죬��Ϊ����Ҫ�����Ĺ��죬ֻҪ���������������
			:_pCur(pCur)
		{}
		//����ָ��ķ�ʽ����Ӧ��
		T& operator*()  //���ؽڵ��е�����
		{
			return _pCur->_data;
		}
		//T* operator->()   //�ⲽ������ë���𣿸о��ù�
		//{
		//	return &(_pCur->_data);
		//}
		list_iterator& operator++()
		{
			_pCur = _pCur->_next;
			return *this;
		}
		list_iterator operator++(int)
		{
			list_iterator temp(*this);
			_pCur = _pCur->_next;
			return temp;
		}
		list_iterator& operator--()
		{
			_pCur = _pCur->_prv;
			return *this;
		}
		list_iterator operator--(int)
		{
			list_iterator temp(*this);
			_pCur = _pCur->_prv;
			return temp;
		}
		bool operator!=(const list_iterator& p)
		{
			return _pCur != p._pCur;
		}
		bool operator==(const list_iterator& p)
		{
			return _pCur == p._pCur;
		}
		Node* _pCur;
	};
	template<class Iterator,class T>   //��һ��������������������ڶ��������ǽڵ������
	struct list_reverse_iterator
	{
		typedef list_reverse_iterator<Iterator,T> self;
		list_reverse_iterator(Iterator it)
		:_it(it)
		{}
		T& operator* ()
		{
			Iterator temp = _it;
			--temp;
			return *temp;
		}
		self operator++()
		{
			--_it;
			return *this;
		}
		self operator++(int)
		{
			self temp(*this);
			_it--;
			return *this;
		}
		bool operator!=(const self& s)
		{
			return _it != s._it;
		}
		bool operator==(const self& s)
		{
			return _it == s._it;
		}
		Iterator _it;
	};








	template<class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
	public:
		typedef list_iterator<T> iterator;   //�����TҲ�ǽڵ��еı��������ͣ�ȫ������T���Ǳ�������
		typedef list_reverse_iterator<iterator, T>reverse_iterator;
		list()
		{
			Creat(); //�յĳ�ʼ����ֱ��ֻ��һ��ͷ
		}
		list(int n, const T& data)
		{
			Creat();
			for (int i = 0; i < n; ++i)
				push_back(data);
		}
		template<class Iterator>  //���乹�첻һ���Ǳ�������仹�п�������vector��������
		list(Iterator first, Iterator end)
		{
			Creat();
			while (first != end)
				push_back(*first++);
		}
		list(const list<T>& L)
		{
			Creat();
			Node* cur = L.first->_next;
			while (cur != L.first)
			{
				push_back(cur->_data);
				cur = cur->_next;
			}
		}
		list& operator=(const list<T>& L)
		{
			if (this != &L)
			{
				clear();//�����Ч��㣬����ͷ����
				Node* cur = L.first->_next;
				while (cur != L.first)
				{
					push_back(cur->_data);
					cur = cur->_next;
				}
			}
			return *this;
		}
		~list()
		{
			clear();  //�����Ч�ӽ��
			delete first;  //�ͷ�ͷ���
		}
		iterator begin()
		{
			return first->_next;  //���Կ�������ȥ�Ĳ����ǽڵ����͵�ָ��
		}
		iterator end()
		{
			return first;
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());  //���Կ�������ȥ�Ĳ����ǽڵ����͵�ָ��
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		int size()const
		{
			int count = 0;
			Node* cur = first->_next;
			while (cur != first)
			{
				count++;
				cur = cur->_next;
			}
			return count;
		}
		bool empty()
		{
			return first->_next == first;
		}
		void resize(int newsize,const T& data = T())
		{
			int oldsize = size();
			if (newsize > oldsize)
			{
				for (int i = oldsize; i < newsize; ++i)
				{
					push_back(data);
				}
			}
			else
			{
				for (int i = newsize; i < oldsize; ++i)
				{
					pop_back();
				}
			}
		}
		T& front()
		{
			return first->_next->_data;
		}
		const T& forst() const
		{
			return first->_next->_data;
		}
		T& back()
		{
			return first->_prv->_data;
		}
		const T& back() const
		{
			return first->_prv->_data;
		}
		void push_back(const T& data)
		{
			insert(end(), data);
		}
		void pop_back()
		{
			erase(--end());
		}
		void push_front(const T& data)
		{
			insert(begin(), data);
		}
		void pop_front()
		{
			erase(begin());
		}
		iterator insert(iterator pos,const T& data)
		{
			Node* p = new Node;
			Node* pCur = pos._pCur;
			p->_data = data;
			p->_next = pCur;
			p->_prv = pCur->_prv;
			p->_prv->_next = p;
			p->_next->_prv = p;
			return iterator(p);
		}
		iterator erase(iterator pos)
		{
			Node* pCur = pos._pCur;
			if (pCur == first)
				return end();
			Node* pres = pCur->_next;
			pCur->_prv->_next = pCur->_next;
			pCur->_next->_prv = pCur->_prv;
			delete pCur;
			return iterator(pres);
		}
		//ͷɾ��
		void clear()
		{
			Node* cur = first->_next;
			while (cur != first)
			{
				first->_next = cur->_next;
				delete cur;
				cur = first->_next;
			}
			first->_next = first;   //���֮������Ҫ�ָ�ԭ״���տ�ʼû�лָ������˰������
			first->_prv = first;
		}
		void swap(list<T>&  L)  //ֻ�轻��ָ��
		{
			swap(first, L.first);
		}
	private:
		void Creat()
		{
			first = new Node;
			first->_next = first;
			first->_prv = first;
		}
	private:
		Node* first;
	};
	void test()
	{
		list<int> L1;
		list<int> L2(10, 5);
		auto it1 = L2.begin();
		while (it1 != L2.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;
		vector<int> v{ 1, 2, 3, 4, 5 };
		list<int> L3(v.begin(),v.end());
		auto it2 = L3.begin();
		while (it2 != L3.end())
		{
			cout << *it2 << " ";
			++it2;
		}
		cout << endl;
		list<int> L4(L3);
		auto it3 = L4.begin();
		while (it3 != L4.end())
		{
			cout << *it3 << " ";
			++it3;
		}
		cout << endl;
		L2 = L4;
		auto it4 = L2.begin();
		while (it4 != L2.end())
		{
			cout << *it4 << " ";
			++it4;
		}
		cout << endl;		
	}
	void test2()
	{
		list<int> L;
		L.push_back(1);
		L.push_back(2);
		L.push_back(3);
		L.push_back(4);
		L.push_back(5);
		auto it1 = L.begin();
		while (it1 != L.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;
		L.pop_back();
		L.pop_back();
		it1 = L.begin();
		while (it1 != L.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;
		L.push_front(0);
		L.push_front(-1);
		L.push_front(-2);
		it1 = L.begin();
		while (it1 != L.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;
		L.pop_front();
		L.pop_front();
		L.pop_front();
		it1 = L.begin();
		while (it1 != L.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;
	}
	void test3()
	{
		vector<int> v{ 1, 2, 3, 4, 5 };
		list<int> L(v.begin(), v.end());
		auto it = L.begin();
		//L.erase(it);  //��ɵ�����ʧЧ
		while (it != L.end())
		{
			cout << *it << endl;
			it++;
		}
	}
}
//using namespace N1;
int main()
{
	//test();
	//test2();
	//test3();
	vector<int*> v;
	v.resize(10);
	cout << v.size() << endl;
	for (int i = 0; i < 10; ++i)
	{
		v[i] = new int[10];
		for (int j = 0; j < 10; ++j)
		{
			v[i][j] = i;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << v[i][j];
		}
	}
	return 0;
}