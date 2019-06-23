#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class mystring
{	
public:
	friend ostream& operator <<(ostream& cout,mystring & p);  //��ʼ��<<�����
	friend istream& operator >>(istream& cin, mystring & p);  //��ʼ��>>�����
	mystring();//Ĭ�ϳ�ʼ��
	mystring(char *a);//�вγ�ʼ��
	mystring(const mystring &p);//��������
	mystring& operator=(char *a);//=���أ����������ַ����������
	mystring& operator= (mystring &p);//=���أ��������Զ��������
	char& operator[](int a);//����[]
	mystring operator+(mystring &p); //+���������
	mystring operator+(char *a);
	~mystring();//��������
private:
	char *mystr;     //�����ַ�������
	int mysize;        //�����ַ�������
};
mystring::mystring(char *a) //�вι��캯����ʵ��
{
	this->mystr = new char[strlen(a) + 1];
	strcpy(this->mystr, a);
	this->mysize = strlen(a);
}
mystring::mystring(const mystring &p)//�������캯��
{
	this->mystr = new char[strlen(p.mystr) + 1];
	strcpy(this->mystr, p.mystr);
	this->mysize = p.mysize;
}
mystring::~mystring() //��������
{
	if (this->mystr != NULL)
	{
		delete[] this->mystr;
		this->mystr = NULL;
	}
}
ostream& operator <<(ostream& cout,mystring & pp)//�������ز���Ҫ�ں����ڲ���������ȫ�ֺ������ɣ����ǵ�Ҫ��Ԫ��
{
	cout << pp.mystr << endl;
	return cout;
}
istream& operator >>(istream& cin,mystring & p)
{
	if (p.mysize != NULL)     //����ɾ��ԭ�пռ�����
	{
		delete[] p.mystr;
		p.mystr = NULL;
	}
	char buf[1024];              //����һ����������Ϊ�м�洢��
	cin >> buf;                     //��������
	p.mystr = new char[strlen(buf) + 1];  //���������µĿռ�
	strcpy(p.mystr, buf);
	p.mysize = strlen(buf);
	return cin;
}
mystring& mystring::operator=(char *a)
{
	if (this->mystr != NULL)
	{
		delete[] this->mystr;
		this->mystr = NULL;
	}
	this->mystr = new char[strlen(a) + 1];
	strcpy(this->mystr, a);
	this->mysize = strlen(a);
	return *this;
}
mystring& mystring::operator=(mystring &p)
{
	if (this->mystr != NULL)
	{
		delete[] this->mystr;
		this->mystr = NULL;
	}
	this->mystr = new char[strlen(p.mystr) + 1];
	strcpy(this->mystr, p.mystr);
	this->mysize = p.mysize;
	return *this;
}
char& mystring::operator[](int a)
{
	return this->mystr[a];
}
mystring mystring::operator+(mystring &p)
{
	int newsize = this->mysize + p.mysize + 1;
	char *pp = new char[newsize];
	memset(pp, 0, newsize);
	strcat(pp, this->mystr);
	strcat(pp, p.mystr);
	mystring newstr(pp);
	delete[] pp;
	return newstr;
}
mystring mystring::operator+(char *a)
{
	int newsize = this->mysize + strlen(a) + 1;
	char *pp = new char[newsize];
	memset(pp, 0, newsize);
	strcat(pp, this->mystr);
	strcat(pp, a);
	mystring newstr(pp);
	delete[] pp;
	return newstr;
}
void test()                      //���Ժ���1
{
	mystring p1("�󼦰�");
	mystring p2 = "lajio";
	cout << p2;
	cout << p1;
	cout << "������������" << endl;
	cin >> p1;
	cout << p1;
} 
void test2()                           //���Ժ���2 
{
	mystring p1("������");
	mystring p2="csdlkcs3123";  //������mystring p2="csdlkcs3123";�͵���mystring p2(csdlkcs3123),���Ե��õ����вι��캯��      
	p2 = p1;                    //�ö�����и�ֵ����=�������أ���������ؾ�ֻ�ǽ��м򵥵�ֵ���������д����ڶ��ϵ�ֵ����Ҫ���ǽ�������	
	p2 = "1321654chuaih";       //������p2="1321654chuaih"����ͬ������Ŀ�����������������Ҫ��ʵ�������Ҫ��=�Ž��п�������
	cout << p2;
	p2[0] = 'w';                       //��ĳ���ַ������滻
	cout << p2[0] << endl;             //��ʵ��һ������������Ԫ�صĲ���
}
void test3()
{
	mystring p11("�װ�");
	mystring p22("���߼������");
	mystring p33=" ";
	p33 = p22 + p11;//���ؼӺ������
	cout << p33;
}
int main()
{
	//test();
	//test2();
	test3();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class gonggong
{
public:
	void laji()
	{
	
	}
	int s;
};

class news: public gonggong
{
public:
	void lajilaji()
	{
		cout << s;
	}

};

class musuy :public news
{
public:
	void lallala()
	{
		cout << s;
    }
};
void test()
{
	news a;
	a.laji;
}


int main()
{

}
#endif
#if 0
#include<iostream>
using namespace std;
class father
{
public:
	father()
	{
		this->b = 100;
	}
	void fun()
	{
		cout << "���Ǹ���fun" << endl;
	}
	void fun(int a)
	{
		cout << "���Ǹ��ຯ������" << endl;
	}
	int b;
};
class son:public father
{
public:
	son()
	{
		this->b = 200;
	}
	void fun()
	{
		cout << "��������fun����" << endl;
	}
	int b;
};
void test()
{
	son p;
	cout << p.b << endl;  //��ӡ�����200����Ϊ�����븸��ͬ����ô�ͻ��оͽ�ԭ��
	//���Ҫ���ø����е�ֵ����ô�ͱ������������,����ͬ������Ҳ�������Ĳ���
	cout << p.father::b << endl;
	//������˵һ���������
	p.father::fun(10);
	// p.fun(10);        //�������޷����ʵģ�������������������ຬ��ͬ���ĺ�������ô������������ͬ��������������������صĺ����ͻᱻ���ǵ���Ҫ���ʾ�Ҫ����������
	p.father::fun();
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class father
{
public:
	static int a;
};
int father::a = 10;
class son:public father
{
public:
	static int a;
};
int son::a = 20;
void test()
{
	son p;
	cout << p.a << endl;
	cout << p.father::a<<endl;
	//����Ա����������Լ̳�����
	cout << son::a << endl;    //��������a
	cout << father::a << endl;   //���ʸ���a
}
int main()
{
	test();
	return 0;
}
# endif
#if 0
#include<iostream>
using namespace std;
class father
{
public:
	father()
	{
		cout << "���Ǹ��๹�캯��" << endl;
	}
	~father()
	{
		cout << "���Ǹ�����������" << endl;
	}
	int a;
};
class son :public father
{
public:
	son()
	{
		cout << "�������๹�캯��" << endl;
	}
	~son()
	{
		cout << "�����������������" << endl;
	}
	int b;
};
int main()
{
	son a;
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class father
{
public:
	virtual void funa()     //������Ϲؼ���ʹ�ú�������麯��
	{
		cout << "������˵��" << endl;
	}
	virtual void funb()
	{
		cout << "�����ɣ�������" << endl;
	}
};
class son :public father
{
public:
	void funa()
	{
		cout << "Сè��˵��" << endl;
	}
	void funb()
	{
		cout << "��ʺ����" << endl;
	}
};
//��Ϊ�����ຯ���ж���funa��������������е�funaǰ�治�ӹؼ��ʱ�Ϊ�麯���Ļ�
//��ô������going������ʱ�򣬵�ַ������ˣ��ڱ���׶ξ�ȷ�����˵�ַ
//�����ຯ������麯��֮����ô�ͻ������е�ʱ����ȥȷ��������ַ������ʱ��
//�ҷ���������ʱ����ȥ���ø����е�funa����Ҫ��������father����
void going(father & a)      //���������Ƕ���ĺ�������ʱ�Ǹ�����󣬶����δ������������               
{                           // Ҳ����˵�����ָֻ���������ָ��������Ķ��� ��Ҳ���Ƕ�̬�Ķ���
	a.father::funb();
}
void test()
{
	son p;         //���ﶨ���������Ķ�������溯�����ݵĲ����Ǹ��࣬���˵�����ڷ����̳й�ϵ��ʱ������������������ת��
	going(p);
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class jisuanqi
{
public:
	//�麯�� virtual int jieguo(){return 0;}
	virtual int jieguo() = 0;       //���麯��
	void seta(int aa,int bb)         //����������˴��麯����ô����̳��˸��࣬��ô�ͱ���ʵ�ָ����е��麯��
	{                              //���˴��麯����ô����Ͳ�����ʵ���������ˣ������Ƕ��ϻ���ջ�϶���������
		this->a = aa;              //���麯���ֳ�Ϊ������
		this->b = bb;
	}
	int a;
	int b;
};
class jiafa : public jisuanqi
{
public:
	int jieguo()
	{
		return a + b;
	}
};
class jianfa :public jisuanqi
{
public:
	int jieguo()
	{
		return a - b;
	}
};
void test()
{
	jisuanqi *abc =new jiafa;
	abc->seta(10, 10);
	cout << abc->jieguo() << endl;
	
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class father
{
public:
	virtual	void sleep()
	{
		cout << "�ְ���˯��" << endl;
	}
	/* virtual ~father()
	{
		cout << "���������" << endl;
	}*/
	//��������,����ʵ��
	virtual ~father()=0;
};
father::~father()
{
	cout << "���������" << endl;
}
class son :public father
{
public:
	 void sleep()
	{
		cout << "������˯��" << endl;
	}
	son(const  char * a)
	{
		this->name = new char[strlen(a) + 1];
		//����������һ��Ҫ˵���ľ����ڵ��ԵĹ�����char��strlen��a��+1����char[strlen(a)+1]
		//���������ʽֻ�����ŵ���������ǰ�߻���delete��ʱ�����
		//�Ҳ²���ܺ�delete[]������[]�йذ�!�������Ժ��Ǿ���д[],�淶��д
		strcpy(this->name, a);
	}
	~son()             //��ͨ���������������������� ���ᵼ���������ɾ�
	{                  //���������������������������������������麯���ӵĹؼ���һ��virtual�ڸ�����������
		cout << "���������" << endl;
		if (this->name != NULL)
		{
			delete[]this->name;
			this->name = NULL;
		}
	}
	char *name;
};
void test()
{
	father *p = new son("������");
	/*father a;
	father *pp = new father;*/
	//p->father::sleep();
	p->sleep();
	delete p;       //������������ͷŵ��Ǹ���Ŀռ䣬ȴ�޷����������������������ͷ�����ռ�
}
int main()
{
	test();
	return 0;
}
#endif
#include<stdio.h>
#include<string.h>
int main()
{
	char a[20]="lajilaji";
	printf("%d\n", sizeof(a));
	int aa=strlen(a);
	printf("%d\n", aa);
	return 0;
}














