#include<iostream>
using namespace std;
template<class T>
class person
{
public:
	T myname;
};
class dog : public person<int>   //1.д��������
{

};
template<class T1,class T2>
class dog2 : public person<T2>   //2.�û��Զ��������T2ֱ�Ӿ��ǻ����T����
{
public:
	T1 myname;
};
