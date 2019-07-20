
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
	vector<int>p1(p,p+sizeof(p)/sizeof(int));     //������൱����123456���p1��(p,p+sizeof(p)/sizeof(int))p���൱��begin,p+sizeof(p)/sizeof(int)���൱��end
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
	v1.swap(v);         //����������֮�е����ݻ���
	printfs(v1);
	if (v1.empty())     //�ж����� �Ƿ�Ϊ�գ�����ֵ��bool���ͣ�Ϊ�շ���1����Ϊ�շ���0
	{
		cout << "Ϊ��" << endl;
	}
	else
		cout << "���ǿ�" << endl;
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
	cout << "����" << v.capacity() << endl;         //����12138
	cout << "��С" << v.size() << endl;             //��С10000
	v.resize(3);
	cout << "����" << v.capacity() << endl;         //����12138
	cout << "��С" << v.size() << endl;				//��С3
	vector<int>(v).swap(v);
	cout << "����" << v.capacity() << endl;         //����3
	cout << "��С" << v.size() << endl;				//��С3
}
//�������vector<int>(v).swap(v);��һ�½���
//vector<int>(v)����v������һ�������������������ص㣺��ǰ�н����ռ��ͷţ�
//Ȼ��ͻ�õ���С��������Ϊ3����������Ȼ��������swap�������ݣ�ʵ�����ǽ���ָ��ָ��ָ�򣩣�����ָ�򽻻���Ŀռ�
//��ǰ�н���ָ��ɿռ�Ķ����ͷ�
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
		if (p != &v[0])           //10000���ռ䲻��һ�ο��ٵģ����Ǹ�������β����������������ģ�
		{                         //����˳��Ľṹʹ����չ��ʱ��ɿռ���治һ�����㹻���¿ռ�
			p = &v[0];            //����ÿ��һ���µĿռ���Ԫ�ص�ַ�ͻᷢ���ı䣬���ǵ�Ŀ�ľ��ǲ鿴�����˶��ٴοռ�
			++num;
		}
	}
	cout << num << endl;
}
void test()
{
	vector<int>v;
	v.reserve(10000);                  //�����������ȣ�reserve����ֱ�Ӹ�����Ԥ����10000���ռ䣬
	int* p = nullptr;                  //��ʱ������֪����������������ȽϽ�ʡʱ��
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
	v.insert((++v.begin()), 2, 100);        //��һ�����������ǵ�������Ҳ����ָ�룬�ڶ����������п��ޣ�
	printfs(v);                             //Ҫ��û��Ĭ����1��Ҫ���еĻ�������Ҫ����ĵ����������ĸ���
	v.pop_back();   //βɾ
	printfs(v);
	v.erase(v.begin());         //ָ��������ɾ��
	printfs(v);
	v.erase((v.begin())+2, v.end());       //ָ����������Χɾ��    (v.begin())+ָ���������intλ
	printfs(v);
	v.clear();      //�������
	printfs(v);
	if (v.empty())       //�ж��Ƿ�Ϊ�գ�Ϊ�շ���1
	{
		cout << "�����\n";
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
		cout << (*it)<<" ";         //����ע�����㣬��һ����������ṩ�ĵ�������reverse_iterator
	}                               // ���ʹ�õ���Ȼ��++it,��ΪΪ��ʹ�÷����˼��ڲ��Ѿ�ά������
	cout << endl;
}
void test2()
{
	//vector��������������ʵ�������ʲô��������ʵ�������
	vector<int>v;
	vector<int>::iterator it = v.begin();
	it = it + 3;
	//֧������д���Ķ���������ʵ�������������ʾ��ǿ���ͨ����������ָ�룩��ָ������ķ��������е�����

}
int main()
{
	test1();
	return 0;
}
#endif