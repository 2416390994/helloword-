#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[3];
	int t;
	printf("请输入个3个数字\n");
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &a[i]);
	}
	if (a[0] < a[1])

	{
		t = a[0];
		a[0] = a[1];
		a[1] = t;
	}
	if (a[1] < a[2])
	{
		t = a[1];
		a[1] = a[2];
		a[2] = t;
	}
	if (a[0] < a[1])
	{
		t = a[0];
		a[0] = a[1];
		a[1] = t;
	}
	printf("%d%d%d", a[0], a[1], a[2]);
	system("pause");
	return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//int main(){
//	int a, b, c, temp;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b) temp = a, a = b, b = temp;
//	if (b < c) temp = b, b = c, c = temp;
//	if (a < b) temp = a, a = b, b = temp;
//	printf("%d %d %d", a, b, c);
//	system("pause");
//	return 0;
//}