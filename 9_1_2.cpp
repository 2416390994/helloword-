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
float max2(void(*)(int))  //��������
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
	int(*p)(int);    //����ָ�룬p��ʾ�ľ���һ��ָ�򷵻�ֵΪ�������Ͳ���Ϊ�������͵ĺ�����ָ��
	 
	p = max;
	p(2);   //����max�����루*p��(2)ͬ��
	(*p)(2);
	(float(*)(void))p;  
	//����û��p�Ļ���(float(*)(void))��ʾ�ľ��ǣ�һ��ָ�򷵻�ֵΪ���������ͣ�����Ϊvoid���͵�ָ�������ת����,����p֮�����˼����
	//��p�������ָ��ָ������ͽ���ת�䣬
	//(*(void(*)())0)();
	void(*post(int, void(*)(int)))(int);//һ����������
	typedef void(*HEAS) (int);   //��ʾHEAS��һ��ָ�򷵻�ֵ��void���ͣ�������int���͵�ָ��
	//HEAS����void(*) (int)
	//��ôvoid(*post(int, void(*)(int)))(int);���Ա�ʾΪ
	HEAS post(int, HEAS);

	return 0;
}