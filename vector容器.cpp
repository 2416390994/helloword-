
#if 0
void test()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		cout << v.capacity() << endl;
	}
	cout << v[2];
}


void test()
{
	int p[] = { 1, 2, 3, 4, 5, 6 };
	vector<int>p1(p,p+sizeof(p)/sizeof(int));     //这个就相当于用123456填充p1。(p,p+sizeof(p)/sizeof(int))p就相当于begin,p+sizeof(p)/sizeof(int)就相当于end
	vector<int>p2(p1.begin(), p1.end());
	printfs(p1);
	printfs(p2);
}
#endif

#if 0
void test2()
{
	vector<int>v(10, 100);
	vector<int>v1(5, 10);
	v1.swap(v);         //将两个容器之中的数据互换
	printfs(v1);
	if (v1.empty())     //判断容器 是否为空，返回值是bool类型，为空返回1，不为空返回0
	{
		cout << "为空" << endl;
	}
	else
		cout << "不是空" << endl;
}
#endif
#if 0
void test2()
{
	vector<int>v;
	for (int i = 0; i < 10000; ++i)
	{
		v.push_back(i);
	}
	cout << "容量" << v.capacity() << endl;         //容量12138
	cout << "大小" << v.size() << endl;             //大小10000
	v.resize(3);
	cout << "容量" << v.capacity() << endl;         //容量12138
	cout << "大小" << v.size() << endl;				//大小3
	vector<int>(v).swap(v);
	cout << "容量" << v.capacity() << endl;         //容量3
	cout << "大小" << v.size() << endl;				//大小3
}
//这里关于vector<int>(v).swap(v);做一下解释
//vector<int>(v)利用v来构造一个匿名对象（匿名对象特点：当前行结束空间释放）
//然后就会得到大小和容量都为3的匿名对象，然后再利用swap交换数据（实际上是交换指针指的指向），对象指向交换后的空间
//当前行结束指向旧空间的对象被释放
#endif
#if 0
void test2()
{
	vector<int>v;
	int* p = nullptr;
	int num = 0;
	for (int i = 0; i < 10000; ++i)
	{
		v.push_back(i);
		if (p != &v[0])           //10000个空间不是一次开辟的，而是根据数据尾插来进行慢慢扩大的，
		{                         //但是顺序的结构使得扩展的时候旧空间后面不一定有足够的新空间
			p = &v[0];            //所以每找一次新的空间首元素地址就会发生改变，我们的目的就是查看更换了多少次空间
			++num;
		}
	}
	cout << num << endl;
}
void test()
{
	vector<int>v;
	v.reserve(10000);                  //与上面代码相比，reserve就是直接给容器预留出10000个空间，
	int* p = nullptr;                  //这时候在已知容量的情况下这样比较节省时间
	int num = 0;
	for (int i = 0; i < 10000; ++i)
	{
		v.push_back(i);
		if (p != &v[0])          
		{                         
			p = &v[0];            
			++num;
		}
	}
	cout << num << endl;
}

int main()
{
	test2();
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
#include<vector>
void printfs(vector<int> s)
{
	for (vector<int>::iterator it = s.begin(); it <s.end(); ++it)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	cout << v.front() << endl;
	cout << v.back() << endl;
	v.insert((++v.begin()), 2, 100);        //第一个参数必须是迭代器，也就是指针，第二个参数可有可无，
	printfs(v);                             //要是没有默认是1，要是有的话就是你要插入的第三个参数的个数
	v.pop_back();   //尾删
	printfs(v);
	v.erase(v.begin());         //指定迭代器删除
	printfs(v);
	v.erase((v.begin())+2, v.end());       //指定迭代器范围删除    (v.begin())+指针后移两个int位
	printfs(v);
	v.clear();      //清空数据
	printfs(v);
	if (v.empty())       //判断是否为空，为空返回1
	{
		cout << "已清空\n";
	}
}
void test1()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	printfs(v);
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << (*it)<<" ";         //这里注意两点，第一点逆序遍历提供的迭代器是reverse_iterator
	}                               // 最后使用的仍然是++it,因为为了使用方便人间内部已经维护好了
	cout << endl;
}
void test2()
{
	//vector迭代器是随机访问迭代器，什么是随机访问迭代器？
	vector<int>v;
	vector<int>::iterator it = v.begin();
	it = it + 3;
	//支持这种写法的都是随机访问迭代器，随机访问就是可以通过迭代器（指针）的指向，随机的访问容器中的数据

}
int main()
{
	test1();
	return 0;
}
#endif