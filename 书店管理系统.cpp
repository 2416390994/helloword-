#include<iostream>
#include<string>
using namespace std;
struct BOOK
{
	int ID;
	double money;
	string book_name;
};
struct List
{
	BOOK* elem = nullptr;
	long long size;
};
void menu()
{
	cout << " +++++++++++++++++++++++++++++++++++++" << endl;
	cout << " +         书店自助查询系统          +" << endl;
	cout << " +++++++++++++++++++++++++++++++++++++" << endl;
	cout << " +                                   +" << endl;
	cout << " +         1.建立系统                +" << endl;
	cout << " +         2.添加新书籍              +" << endl;
	cout << " +         3.删除书籍                +" << endl;
	cout << " +         4.查找书籍                +" << endl;
	cout << " +         5.更改书籍信息            +" << endl;
	cout << " +         6.退出系统                +" << endl;
	cout << " +++++++++++++++++++++++++++++++++++++" << endl;
	cout << "                                 v 1.0" << endl;
}
//创建系统
int CreatSystem(List* list)
{
	system("cls");
	cout << "你的选择是建立系统" << endl;
	list->elem = new BOOK[100];
	list->size = 0;
	if (list->elem == nullptr)
		return -1;
	else
		return 1;
}
//增加书籍
void Add_New_Book(List* list)
{
	if (list->elem == nullptr)
	{
		system("cls");
		cout << "还未建立系统,无法添加书籍" << endl;
	}	
	else
	{
		string bookname;
		int id;
		int flag;
		double money;
		cout << "请输入书的名称:";
		cin >> bookname;
		cout << "请输入书的价格:";
		cin >> money;
		cout << "请输入书的ID:";
		cin >> id;
		list->elem[list->size].book_name = bookname;
		while (1)
		{
			flag = 0;
			for (int i = 0; i < list->size; ++i)
			{
				if (list->elem[i].ID == id)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				cout << "ID重复请，重新输入ID:";
				cin >> id;
			}
			else
				break;
		}
		list->elem[list->size].ID = id;
		list->elem[list->size].money = money;
		list->size++;
		system("cls");
		cout << "插入成功" << endl;
	}
}
//查看所有书籍
int See_All_Book(List* list)
{
	if (list->elem == nullptr)
	{
		cout << "还未创建系统，无法使用此功能" << endl;
		return -1;
	}
	if (list->size == 0)
	{
		system("cls");
		cout << "此系统为空，还未添加书籍" << endl;
		return -1;
	}
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "ID" << "\t\t\t" << "书名" << "\t\t\t" << "价格" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	for (int i = 0; i < list->size; ++i)
	{
		cout << list->elem[i].ID << "\t\t\t" << list->elem[i].book_name << "\t\t\t" << list->elem[i].money << endl;
		cout << "-----------------------------------------------------------" << endl;
	}
	return 1;
}
//退出系统
int Close_System()
{
	return 0;
}
//删除书籍
void delete_book(List* list)
{
	int id;
	int i;
	int j;
	cout << "返回上一级请输入-1!!!" << endl;
	cout << "请选择你所要删除的书籍的ID:";
	cin >> id;
	while (1)
	{
		if (id == -1)
		{
			system("cls");
			cout << "返回成功" << endl;
			break;
		}
		for (i = 0; i < list->size; ++i)
		{
			if (list->elem[i].ID == id)
				break;
		}
		if (i < list->size)
		{
			for (j = i; j < list->size - 1; ++j)
			{
				list->elem[j].book_name = list->elem[j + 1].book_name;
				list->elem[j].ID = list->elem[j + 1].ID;
				list->elem[j].money = list->elem[j + 1].money;
			}
			list->size--;
			system("cls");
			cout << "删除成功" << endl;
			break;
		}
		else
			cout << "ID输入有误，请重新输入";
		cin >> id;
	}
}
//查找书籍
void Find_Book(List* list)
{
	int i = 0;
	int flag = 1;
	string bookname;
	int ID;
	int choices;
	while (flag == 1)
	{
		cout << "请选择你所要查找的方式：1.按书籍名称 2.按照书籍ID" << endl;
		cout << "请输入你的选择:";
		cin >> choices;
		if (choices == 1)
		{
			cout << "请输入书籍名称:";
			cin >> bookname;
			for (; i < list->size; ++i)
			{
				if (bookname == list->elem[i].book_name)
				{
					system("cls");
					cout << "已找到" << endl;
					cout << "你所找的" << bookname << "的ID是" << list->elem[i].ID << endl;
					cout << "他的价格是" << list->elem[i].money << "元" << endl;
					flag = 0;
					break;
				}
			}
		}
		else if (choices == 2)
		{
			cout << "请输入书籍ID:";
			cin >> ID;
			for (; i < list->size; ++i)
			{
				if (bookname == list->elem[i].book_name)
				{
					system("cls");
					cout << "已找到" << endl;
					cout << "你所找的" << bookname << "的ID是" << list->elem[i].ID << endl;
					cout << "他的价格是" << list->elem[i].money << "元" << endl;
					flag = 0;
					break;
				}
			}
		}
		else
		{
			cout << "输入有误,请重新输入" << endl;
		}
		if (i == list->size)
		{
			cout << "没找到你所查找的书籍" << endl;
			break;
		}
	}
}
int choice(List* list)
{
	int chooce;
	cout << "请输入你要执行的操作:";
	cin >> chooce;
	if (chooce == 1)
	{
		if (CreatSystem(list) == 1)
			cout << "创建成功" << endl;
		else
			cout << "创建失败" << endl;
	}
	if (chooce == 2)
	{
		Add_New_Book(list);
	}
	if (chooce == 3)
	{
		if (See_All_Book(list) != -1)
			delete_book(list);
	}
	if (chooce == 4)
	{
		Find_Book(list);
	}
	if (chooce == 6)
	{
		return -1;
	}
	return 1;
}
int main()
{
	List list;
	while (1)
	{
		menu();
		int ret = choice(&list);
		if (ret == -1)
			break;
	}
	return 0;
}
