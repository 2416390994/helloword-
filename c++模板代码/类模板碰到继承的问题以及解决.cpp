#include<iostream>
using namespace std;
template<class T>
class person
{
public:
	T myname;
};
class dog : public person<int>   //1.写死的类型
{

};
template<class T1,class T2>
class dog2 : public person<T2>   //2.用户自定义的类型T2直接就是基类的T类型
{
public:
	T1 myname;
};
