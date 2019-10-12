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
	cout << " +         ���������ѯϵͳ          +" << endl;
	cout << " +++++++++++++++++++++++++++++++++++++" << endl;
	cout << " +                                   +" << endl;
	cout << " +         1.����ϵͳ                +" << endl;
	cout << " +         2.������鼮              +" << endl;
	cout << " +         3.ɾ���鼮                +" << endl;
	cout << " +         4.�����鼮                +" << endl;
	cout << " +         5.�����鼮��Ϣ            +" << endl;
	cout << " +         6.�˳�ϵͳ                +" << endl;
	cout << " +++++++++++++++++++++++++++++++++++++" << endl;
	cout << "                                 v 1.0" << endl;
}
//����ϵͳ
int CreatSystem(List* list)
{
	system("cls");
	cout << "���ѡ���ǽ���ϵͳ" << endl;
	list->elem = new BOOK[100];
	list->size = 0;
	if (list->elem == nullptr)
		return -1;
	else
		return 1;
}
//�����鼮
void Add_New_Book(List* list)
{
	if (list->elem == nullptr)
	{
		system("cls");
		cout << "��δ����ϵͳ,�޷�����鼮" << endl;
	}	
	else
	{
		string bookname;
		int id;
		int flag;
		double money;
		cout << "�������������:";
		cin >> bookname;
		cout << "��������ļ۸�:";
		cin >> money;
		cout << "���������ID:";
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
				cout << "ID�ظ��룬��������ID:";
				cin >> id;
			}
			else
				break;
		}
		list->elem[list->size].ID = id;
		list->elem[list->size].money = money;
		list->size++;
		system("cls");
		cout << "����ɹ�" << endl;
	}
}
//�鿴�����鼮
int See_All_Book(List* list)
{
	if (list->elem == nullptr)
	{
		cout << "��δ����ϵͳ���޷�ʹ�ô˹���" << endl;
		return -1;
	}
	if (list->size == 0)
	{
		system("cls");
		cout << "��ϵͳΪ�գ���δ����鼮" << endl;
		return -1;
	}
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "ID" << "\t\t\t" << "����" << "\t\t\t" << "�۸�" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	for (int i = 0; i < list->size; ++i)
	{
		cout << list->elem[i].ID << "\t\t\t" << list->elem[i].book_name << "\t\t\t" << list->elem[i].money << endl;
		cout << "-----------------------------------------------------------" << endl;
	}
	return 1;
}
//�˳�ϵͳ
int Close_System()
{
	return 0;
}
//ɾ���鼮
void delete_book(List* list)
{
	int id;
	int i;
	int j;
	cout << "������һ��������-1!!!" << endl;
	cout << "��ѡ������Ҫɾ�����鼮��ID:";
	cin >> id;
	while (1)
	{
		if (id == -1)
		{
			system("cls");
			cout << "���سɹ�" << endl;
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
			cout << "ɾ���ɹ�" << endl;
			break;
		}
		else
			cout << "ID������������������";
		cin >> id;
	}
}
//�����鼮
void Find_Book(List* list)
{
	int i = 0;
	int flag = 1;
	string bookname;
	int ID;
	int choices;
	while (flag == 1)
	{
		cout << "��ѡ������Ҫ���ҵķ�ʽ��1.���鼮���� 2.�����鼮ID" << endl;
		cout << "���������ѡ��:";
		cin >> choices;
		if (choices == 1)
		{
			cout << "�������鼮����:";
			cin >> bookname;
			for (; i < list->size; ++i)
			{
				if (bookname == list->elem[i].book_name)
				{
					system("cls");
					cout << "���ҵ�" << endl;
					cout << "�����ҵ�" << bookname << "��ID��" << list->elem[i].ID << endl;
					cout << "���ļ۸���" << list->elem[i].money << "Ԫ" << endl;
					flag = 0;
					break;
				}
			}
		}
		else if (choices == 2)
		{
			cout << "�������鼮ID:";
			cin >> ID;
			for (; i < list->size; ++i)
			{
				if (bookname == list->elem[i].book_name)
				{
					system("cls");
					cout << "���ҵ�" << endl;
					cout << "�����ҵ�" << bookname << "��ID��" << list->elem[i].ID << endl;
					cout << "���ļ۸���" << list->elem[i].money << "Ԫ" << endl;
					flag = 0;
					break;
				}
			}
		}
		else
		{
			cout << "��������,����������" << endl;
		}
		if (i == list->size)
		{
			cout << "û�ҵ��������ҵ��鼮" << endl;
			break;
		}
	}
}
int choice(List* list)
{
	int chooce;
	cout << "��������Ҫִ�еĲ���:";
	cin >> chooce;
	if (chooce == 1)
	{
		if (CreatSystem(list) == 1)
			cout << "�����ɹ�" << endl;
		else
			cout << "����ʧ��" << endl;
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
