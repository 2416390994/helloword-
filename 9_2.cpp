/*
#include<iostream>
using namespace std;
enum{ red = 2, yellow = 5, blue = 8 };
int main()
{
/*printf("%c%c", (char)0xc1, (char)0xF5);
printf("%c%c", (char)0xEA, (char)0xC5);
printf("%c%c", (char)0xB3, (char)0xBF);
printf("%c%c", (char)0xc4, (char)0xe3);
printf("%c%c", (char)0xba, (char)0xc3);*/
//cout << endl;
/*
int coler;
cin >> coler;
switch (coler)
{
case 2:cout << "ret" << endl;
break;
case 5:cout << "yellow" << endl;
break;
case 8:cout << "blue" << endl;
break;
default:
cout << "À±¼¦" << endl;
}
int a[6] = { 1, 2, 3, 4, 5, 6 };
cout << *(a + 1) << endl;
int * p = a;
cout << *(++p) << endl;
p = &a[0];
cout << *(++p) << endl;
int(*p1)[6];
p1 = &a;
cout << a << endl;
cout << (*p1)[1] << endl;
int b[2][3] = { 1, 2, 3, 4, 5, 6 };
cout << sizeof(b) << endl;
int * p2 = b[0];
cout << *p2 << endl;
cout << *(p2+1) << endl;
int((*p3)[2])[3];
p3 = &b;
//cout << *(*(b + 1) + 1);
int * p4 = &b[0][0];
cout << *(p4+0) << endl;
cout << *(p4+1) << endl;
cout << *(p4+2 )<< endl;
cout << *(p4+3 )<< endl;
//cout << (*(*(p3+1))+1)<< endl;
return 0;
}
*/
//#include<iostream>
//using namespace std;
//#define max(a,b)  (a) > (b) ? (a): (b)
//inline int max2(int a, int b)
//{
//	return (a) > (b) ? (a) : (b);
//}
//inline float max2(float a, float b)
//{
//	return (a) > (b) ? (a) : (b);
//}
//inline double max2(double a, double b)
//{
//	return (a) > (b) ? (a) : (b);
//}
//template
//int main()
//{
//	cout << sizeof(size_t) << endl;
//	double a = 3.2; 
//	double b = 4;
//	//int e = max(a, b);
//	//cout << e << endl;
//	cout << max2(a, b) << endl;
//	return 0;
//}
//#include<stdio.h>
//struct pp
//{
//	char * a;
//	short b;
//	double c;
//	char d;
//	float e;
//	char f;
//	long g;
//	int h;
//};
//int main()
//{
//	cout << sizeof(pp) << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	char *r;
//	//r = (char*)calloc(10,1);  //why
//	//r[0] = 97;
//	//cout << strlen(r) << endl;
//	//cout << *r << endl;
//	r = (char *)calloc(10,sizeof(int));
//	for (int i = 0; i < 40; ++i)
//	{
//		cout << (int)r[i] << endl;
//	}
//	if (!r)
//	{
//		exit(1);
//	}
//	else
//	{
//		cout << "jeseoip" << endl;
//	}
//	free(r);
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//int main()
//{
//	int i, n;
//	int * pData;
//	printf("Amount of numbers to be entered: ");
//	scanf("%d", &i);
//	pData = (int*)calloc(i, sizeof(int));
//	if (pData == NULL) exit(1);
//	for (n = 0; n<i; n++)
//	{
//		printf("Enter number #%d: ", n);
//		scanf("%d", &pData[n]);
//	}
//	printf("You have entered: ");
//	for (n = 0; n<i; n++) printf("%d ", pData[n]);
//	free(pData);
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int input, n;
//	int count = 0;
//	int * numbers = NULL;
//	int * more_numbers;
//
//	do {
//		printf("Enter an integer value (0 to end): ");
//		scanf("%d", &input);
//		count++;
//
//		more_numbers = (int*)realloc(numbers, count * sizeof(int));
//
//		if (more_numbers != NULL) {
//			numbers = more_numbers;
//			numbers[count - 1] = input;
//		}
//		else {
//			free(numbers);
//			puts("Error (re)allocating memory");
//			exit(1);
//		}
//	} while (input != 0);
//
//	printf("Numbers entered: ");
//	for (n = 0; n<count; n++) printf("%d ", numbers[n]);
//	free(numbers);
//
//	return 0;
//}