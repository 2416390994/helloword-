//�ȶ���ð������
/*
#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a[] = { 4, 5, 4, 6, 9, 9, 8, 7, 2, 2, 5, 6, 5 };
	int c = sizeof(a) / sizeof(int);
	for (int i = 0; i < c - 1; ++i)
	{
		for (int j = 0; j < c - 1 - i; ++j)
		{
			if (a[j]>a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				if (a[j + 1] == a[j + 2])  //������һ�ξͿ���ʹð���������ȶ�������
				{
					j++;
				}
			}
		}
	}
	for (int i = 0; i < c; ++i)
	{
		printf("%d", a[i]);
	}
	return 0;
}
*/

/*
#include<stdio.h>
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
int main()
{
int a[] = { 4, 5, 4, 6, 9, 9, 8, 7, 2, 2, 5, 6, 5 };
int c = sizeof(a) / sizeof(int);
for (int i = 1; i < c; ++i)
{
for (int j = i; j>0 && a[j] > a[j - 1]; --j)
{
swap(&a[j], &a[j - 1]);
}
}
for (int i = 0; i < c; ++i)
{
printf("%d", a[i]);
}
return 0;
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a[] = { 4, 5, 4, 6, 9, 9, 8, 7, 2, 2, 5, 6, 5 };
	int c = sizeof(a) / sizeof(int);
	//printf("%d", c);
	int i;
	int j;
	for (i = 0; i < c - 1; i++)
	{
		int max = i;
		for (j = i + 1; j < c; j++)
		{
			if (a[j] > a[max])
			{
				max = j;
			}
		}
		swap(&a[i], &a[max]);
	}
	for (i = 0; i < c; ++i)
	{
		printf("%d", a[i]);
	}
	return 0;
}
*/
/*
//�鲢����
#include<stdio.h>
void sort(int *a, int L, int M, int R)
{
	int *p = new int[R - L + 1];
	int p1 = L;
	int p2 = M + 1;
	int i = 0;
	while (p1 <= M && p2 <= R)
	{
		p[i++] = a[p1] >= a[p2] ? a[p1++] : a[p2++];
	}
	while (p1 <= M)
	{
		p[i++] = a[p1++];
	}
	while (p2 <= R)
	{
		p[i++] = a[p2++];
	}
	for (i = 0; i < R - L + 1; ++i)
	{
		a[L + i] = p[i];
	}
}
void func(int *a, int L, int R)
{
	if (L == R)
		return;
	int M = L + ((R - L) >> 1);
	func(a, L, M);
	func(a, M + 1, R);
	sort(a, L, M, R);
}
int main()
{
	int a[] = { 5, 8, 9, 6, 3, 4, 7, 2, 1, 0 ,0};
	func(a, 0, 10);
	for (int i = 0; i < 11; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
*/

/*
#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void func(int *a, int L, int R)
{
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if ((a[L]) % 2 == 0)
		{
			less++;
			L++;
		}
		else
		{
			swap(&a[L], &a[more--]);
		}
	}
}
int main()
{
	int a[] = { 5, 7, 8, 9, 6, 3, 5, 4, 1, 2 };
	func(a, 0, 9);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
*/
/*
//��һ�����鹹���Ϊһ����
#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapInser(int *a, int i)
{
	while (a[i] > a[(i - 1) / 2])   //�������ﹹ��ľ��Ǵ��
	{
		swap(&a[i], &a[(i - 1) / 2]); //���ӽڵ���ڸ��ڵ��ֵ��ʱ���һֱwhileѭ�������ϻ���ֱ���ҵ����ʵ�λ��
		i = (i - 1) / 2;   //��һ����Ŀ�ľ�������һ�� ������֮����Ƚ������λ�õĸ��ڵ㻹Ҫ����ô��Ҫ׼����while�����ڶ���ѭ���ˣ�����Ҫ�ı�i��λ�ã�ȷ����������ͬһ������
	}
}
void heapsort(int *a, int L)
{
	if (a == NULL || L < 2)
	{
		return;
	}
	for (int i = 0; i < L; i++)
	{
		heapInser(a, i);
	}
}
int main()
{
	int a[] = { 5, 0, 7, 6, 8 };
	int L = sizeof(a) / sizeof(int);
	heapsort(a, L);
	printf("%d", a[0]);
	printf("%d", a[1]);
	printf("%d", a[2]);
	printf("%d", a[3]);
	printf("%d", a[4]);
	//printf("%d", a[5]);
	//printf("%d", a[6]);
	return 0;
}
*/

#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapInser(int *a, int i)
{
	while (a[i] > a[(i - 1) / 2])     // 
	{
		swap(&a[i], &a[(i - 1) / 2]); 
		i = (i - 1) / 2;   
	}
}
void heapify(int *a, int index, int size)
{
	int left = index * 2 + 1;
	//int largest = a[left] > a[left + 1] ? left : left + 1;
	while (left < size)   //�ж��ǲ��Ǵ�����������Ҫ�Ǵ��ڵĻ����ܽ���ѭ��
	{
		int largest = left + 1 < size && a[left + 1] > a[left] ? left + 1 : left;//Ҫȷ�����largest�����Һ������������ 
		largest = a[largest]>a[index] ? largest : index;//��һ���õ���������Ԫ���е�����ߣ�Ҳ����Ŷ����Ҫ��Ҫ���������½���
		if (largest == index)
		{
			break;
		}
		swap(&a[largest], &a[index]);
		index = largest;   //�����±꣬����ͬһ��Ԫ��
		left = index * 2 + 1;    //ȷ����һ������
	}
}
void heapsort(int *a, int L)
{
	int size = L;
	if (a == NULL || L < 2)
	{
		return;
	}
	for (int i = 0; i < L; i++)
	{
		heapInser(a, i);
	}
//=============================================================================//
	//�������Ĳ��������� �����Ѿ��������ɴ�ѵĻ����Ͻ�������
	while (size > 0)
	{
		swap(&a[0], &a[--size]);
		heapify(a, 0, size);
	}
}
int main() 
{
	int a[] = { 5, 0, 7, 6, 8 };
	int L = sizeof(a) / sizeof(int);
	heapsort(a, L);
	printf("%d", a[0]);
	printf("%d", a[1]);
	printf("%d", a[2]);
	printf("%d", a[3]);
	printf("%d", a[4]);
	//printf("%d", a[5]);
	//printf("%d", a[6]);
	return 0;
}
















