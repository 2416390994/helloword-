#include<iostream>
#include<string.h>
using namespace std;
struct {
	int a;
	char * b;
}c[] = {010,"dhewuifhi",025,"gdweugcu",25,"fgweuifhi"};
int max(int a)
{

}
float max2(void(*)(int))  //函数声明
{
}
int main()
{

	//cout << c[1].b << endl;
	/*char a[] = { 'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\n',0};
	cout << strlen(a) << endl << sizeof(a) << endl;
	cout << a << endl;
	int ret = printf("hello world\n");
	char *b = "hello world";
	cout << strlen(b) << endl;
	cout << ret << endl;
	printf("\n");
	char *c = "fjosi'/*'\"\'\"\"hiu''";
	cout << c << endl;*/
	int(*p)(int);    //函数指针，p表示的就是一个指向返回值为整数类型参数为整数类型的函数的指针
	 
	p = max;
	p(2);   //调用max函数与（*p）(2)同义
	(*p)(2);
	(float(*)(void))p;  
	//假如没有p的话，(float(*)(void))表示的就是，一个指向返回值为浮点型类型，参数为void类型的指针的类型转换符,加上p之后的意思就是
	//将p这个函数指针指向的类型进行转变，
	//(*(void(*)())0)();
	void(*post(int, void(*)(int)))(int);//一个函数声明
	typedef void(*HEAS) (int);   //表示HEAS是一个指向返回值是void类型，参数是int类型的指针
	//HEAS就是void(*) (int)
	//那么void(*post(int, void(*)(int)))(int);可以表示为
	HEAS post(int, HEAS);

	return 0;
}