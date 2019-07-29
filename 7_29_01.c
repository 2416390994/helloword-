//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
	/*void print_c(int *a, int n, int m);
	int a[5][5] = { { 1, 2 }, { 3, 4, 5 }, { 6 }, { 7 }, { 0, 8 } };

	printf("\n方法3:\n");
	print_c(&a[0][0], 5, 5);*/
	//int a[10];
	//int *p = NULL;
	//printf("%p\n", &a[0]);
	//printf("%p\n", p);
	//printf("%p", &a[0]+1);
	//char a = "hello";
	////char *e = "hello";
	//char greeting[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	//int w[10] = { 1, 2, 3 };
	//printf("%d\n", sizeof(greeting));
	//
	//printf("%d", sizeof(w));
//	return 0;
//}
//void print_c(int *a, int n, int m) {
//	int i, j;
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < m; j++)
//			printf("%d ",*(a + i*m + j));
//		printf("\n");
//	}
//}
//#include <stdio.h>
//int main()
//{
//	char greeting[10] = { 'H', 'e', 'l', 'l', 'o', '\0','2','5','\0' };
//
//	printf("Greeting message: %s\n", greeting);
//	for (int i = 0; i < 6; ++i)
//	{
//		printf("%c", greeting[i]);
//	}
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include<stdlib.h>
//
//typedef struct Books
//{
//	char  title[50];
//	char*  author;
//	char  subject[100];
//	int   book_id;
//}Books;
//
//int main()
//{
//	Books Book1;        /* 声明 Book1，类型为 Books */
//	//struct Books Book2;        /* 声明 Book2，类型为 Books */
//	Books * p = (Books *)malloc(sizeof(Books));
//	/* Book1 详述 */
//	//strcpy(Book1.title, "C Programming");
//	//strcpy(Book1.author, "Nuha Ali");
//	//printf("%s", Book1.author);
//	char *a= "123456";
//	char *b = "474646874";
//	b = a;
//	//printf("%s", b);
//	//p->author = a;
//	//Book1.author = a;
//	char *c = "hello";
//	strcpy(p->author, c);
//	p->author = a;
//	printf("%s", p->author);
//	//printf("%s",a);
//	//p->author = "13465";
//	//printf("%s", *(p->author));
//
//	//Book1.author = a;
//	//strcpy(Book1.subject, "C Programming Tutorial");
//	//Book1.book_id = 6495407;
//
//	/* Book2 详述 */
//	//strcpy(Book2.title, "Telecom Billing");
//	//strcpy(Book2.author, "Zara Ali");
//	//strcpy(Book2.subject, "Telecom Billing Tutorial");
//	//Book2.book_id = 6495700;
//
//	///* 输出 Book1 信息 */
//	//printf("Book 1 title : %s\n", Book1.title);
//	//printf("Book 1 author : %s\n", Book1.author);
//	//printf("Book 1 subject : %s\n", Book1.subject);
//	//printf("Book 1 book_id : %d\n", Book1.book_id);
//
//	///* 输出 Book2 信息 */
//	//printf("Book 2 title : %s\n", Book2.title);
//	//printf("Book 2 author : %s\n", Book2.author);
//	//printf("Book 2 subject : %s\n", Book2.subject);
//	//printf("Book 2 book_id : %d\n", Book2.book_id);
//
//	return 0;
//}


//struct packed_struct {
//	unsigned int age : 3;
//
//} pack;
//int main()
//{
//	pack.age = 8;
//	printf("%d", pack.age);
//	return 0;
//}
////#include<stdio.h>
////int main()
////{
////	int a = 0x12345678;
////	char * b = (char *)&a;
////	printf("%x", *(b+1));
////
////}
#include<stdio.h>
int main()
{
	int c;
	while ((c = getchar()) != '\n') //会从屏幕上接受一个字符，但是使用int类型的变量把他存储起来
	{  
		putchar(c);
	}
	return 0;
}
