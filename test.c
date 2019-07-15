#if 0
#include<stdio.h>
int main()
{
	const int a = 10;
	int * p = (int *)&a;
	//*p = 20;
	printf("%p\n", p);
	printf("%p\n", &a);
	printf("%d", a);
	return 0;
}
#endif
#if 0
#include<stdio.h>
int main()
{
	const int b = 10;
	int * p = (int *)&b;
	*p = 20;
	printf("%d\n", b);
	int a[10] = { b };
	printf("%d", a[0]);

	return 0;
}
#endif
