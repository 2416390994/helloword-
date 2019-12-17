#include<iostream>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>
using namespace std;

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void Show(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d  ", arr[i]);
	}

	printf("\n");
}

// 冒泡
// O(n^2)   O(1)    稳定 
void BubbleSort(int *arr, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int flag = 0;
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}
	}
}

// 选择
// O(n^2)   O(1)    不稳定
void SelectSort(int *arr, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		Swap(&arr[i], &arr[min]);
	}
}

//直接插入排序   数据越趋于有序，其效率越高
// O(n^2)     O(1)    稳定
//  最坏 O(n^2)   最好 O(n)
void InsertSort(int *arr, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int tmp = arr[i];
		int j = 0;
		for (j = i - 1; j >= 0; --j)
		{
			if (arr[j] > tmp)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}

		arr[j + 1] = tmp;
	}
}

static void Shell2(int *arr, int len, int d)
{
	for (int k = 0; k < d; ++k)
	{
		for (int i = d + k; i < len; i += d)
		{
			int tmp = arr[i];
			int j = i - d;
			for (; j >= 0; j -= d)
			{
				if (arr[j] > tmp)
				{
					arr[j + d] = arr[j];
				}
				else
				{
					break;
				}
			}

			arr[j + d] = tmp;
		}
	}
}
static void Shell(int *arr, int len, int d)
{
	for (int i = d; i < len; ++i)
	{
		int tmp = arr[i];
		int j = i - d;
		for (; j >= 0; j -= d)
		{
			if (arr[j] > tmp)
			{
				arr[j + d] = arr[j];
			}
			else
			{
				break;
			}
		}

		arr[j + d] = tmp;
	}
}

//希尔排序
//  O(n ^1.3~1.5)   O(1)    不稳定  
void ShellSort(int *arr, int len)
{
	// 目前并没有一个合适的固定分组
	//  分组的值需要两两互质，并且最后一个分组必须为1
	int d[] = { 5, 3, 1 };
	for (int i = 0; i < sizeof(d) / sizeof(d[0]); ++i)
	{
		Shell(arr, len, d[i]);
	}
}

//  O(logn)
static void OneAdjust(int *arr, int len, int root)
{
	int i = root;
	int tmp = arr[i];
	int j = 2 * i + 1; //   left
	while (j < len)
	{
		if (j + 1 < len && arr[j] < arr[j + 1])
		{
			j = j + 1;
		}
		//  j 就是左右孩子中较大的哪一个
		if (arr[j] > tmp)
		{
			arr[i] = arr[j];
			i = j;  //  下一个子树的根
			j = 2 * i + 1; //  下一个子树的左孩子
		}
		else
		{
			break;
		}
	}

	arr[i] = tmp;
}

//  O(nlogn) 
static void CreateHeap(int *arr, int len)
{
	int root = len / 2 - 1;
	for (; root >= 0; --root)
	{
		OneAdjust(arr, len, root);  // O(logn)
	}
}

//堆排序
//  O(nlogn)     O(1)      不稳定
void HeapSort(int *arr, int len)
{
	CreateHeap(arr, len);  //  O(nlogn)

	for (int i = 0; i < len - 1; ++i)  // O(n)
	{
		Swap(&arr[0], &arr[len - 1 - i]);

		OneAdjust(arr, len - i - 1, 0);  //  O(logn)
	}
}

// O(n)
static  int  OneQuick(int *arr, int i, int j)
{
	int tmp = arr[i];

	while (i < j)   //   保证找的整个过程  i  < j
	{
		while (i < j)   //  从后向前找比tmp小的元素  保证  i < j
		{
			if (arr[j] < tmp) break;
			j--;
		}

		arr[i] = arr[j];   //   当找到比tmp小的元素后，将j位置的值存储到i位置

		while (i < j)  //  从前向后找比tmp大的元素  保证  i < j
		{
			if (arr[i] > tmp) break;
			i++;
		}

		arr[j] = arr[i];  //   当找到比tmp大的元素后，将i位置的值存储到j位置
	}

	arr[i] = tmp;   //   i之前的数据都比tmp小， 之后的数据都比tmp大

	return i;
}

// O(nlogn)     O(logn)      不稳定
static void Quick(int *arr, int left, int right)
{
	// O(n)
	int mod = OneQuick(arr, left, right);

	if (mod - left > 1)   //  i左边剩余的数据是否超过1个
	{
		Quick(arr, left, mod - 1);
	}
	if (right - mod > 1)  // i右边剩余的数据是否超过1个
	{
		Quick(arr, mod + 1, right);
	}
}

//  
static void  ForQuick(int *arr, int left, int right)
{
	Stack st;
	int size = (int)(log10((double)(right - left + 1)) / log10((double)2));
	size = (size + 1) * sizeof(int)* 2;
	st.data = (int *)malloc(size);
	assert(st.data != NULL);
	st.top = 0;

	st.data[st.top++] = left;
	st.data[st.top++] = right;

	while (st.top != 0)
	{
		right = st.data[--st.top];
		left = st.data[--st.top];

		int mod = OneQuick(arr, left, right);

		if (mod - left > 1)
		{
			st.data[st.top++] = left;
			st.data[st.top++] = mod - 1;
		}
		if (right - mod > 1)
		{
			st.data[st.top++] = mod + 1;
			st.data[st.top++] = right;
		}
	}

	free(st.data);
}

//快速排序
void QuickSort(int *arr, int len)
{
	ForQuick(arr, 0, len - 1);
}

// O(n)
static void Meger(int *arr, int len, int width, int *brr)
{
	int L1 = 0;
	int H1 = L1 + width - 1;
	int L2 = H1 + 1;
	int H2 = L2 + width - 1 < len - 1 ? L2 + width - 1 : len - 1;
	int num = 0;

	while (L1 < len && L2 < len)
	{
		while (L1 <= H1 && L2 <= H2)
		{
			if (arr[L1] < arr[L2])
			{
				brr[num++] = arr[L1++];
			}
			else
			{
				brr[num++] = arr[L2++];
			}
		}

		while (L1 <= H1)
		{
			brr[num++] = arr[L1++];
		}

		while (L2 <= H2)
		{
			brr[num++] = arr[L2++];
		}

		L1 = H2 + 1;
		H1 = L1 + width - 1 < len - 1 ? L1 + width - 1 : len - 1;
		L2 = H1 + 1;
		H2 = L2 + width - 1 < len - 1 ? L2 + width - 1 : len - 1;
	}

	while (L1 <= H1)
	{
		brr[num++] = arr[L1++];
	}

	for (int i = 0; i < len; ++i)
	{
		arr[i] = brr[i];
	}
}

//归并排序
// O(nlogn)    O(n)     稳定
void MegerSort(int *arr, int len)
{
	int *brr = (int *)malloc(sizeof(int)* len);

	for (int i = 1; i < len; i *= 2)
	{
		Meger(arr, len, i, brr);   // O(n)
	}

	free(brr);
}

//  求数组中最大数字的宽度
static int  GetMaxWidth(int *arr, int len)
{
	int max = arr[0];
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] > max)  max = arr[i];
	}

	int width = 0;
	while (max)  //  12
	{
		width++;
		max /= 10;
	}

	return width;
}

//  求data的倒数第i+1位上的值
static int GetNumOfWidth(int data, int i)
{
	while (i)
	{
		data /= 10;
		i--;
	}

	return data % 10;
}

// O(d * n)      O(k + n)     稳定
// 基数排序      不需要比较的排序
void RadixSort(int *arr, int len)
{
	/*
	1、创建队列
	2、先求最大数字的位数
	3、求出相应位数的值， 并根据位数值将其存储相应的队列中
	4、按顺序输出所有队列中的值，  循环处理3,4步，循环次数由第一步算出
	*/

	Que que[10];
	for (int i = 0; i < 10; ++i)
	{
		que[i].data = (int*)malloc(sizeof(int)* len);
		assert(que[i].data != NULL);
		que[i].head = que[i].tail = 0;
	}

	int width = GetMaxWidth(arr, len); // O(n)

	for (int i = 0; i < width; ++i)  // O(d * n)
	{
		//  将数组中所有的数字取其相应位数的值，并将其存储到相应的队列中
		for (int j = 0; j < len; ++j)
		{
			int  num = GetNumOfWidth(arr[j], i);
			que[num].data[que[num].tail++] = arr[j];
		}

		int k = 0;
		for (int m = 0; m < 10; ++m)
		{
			while (que[m].head != que[m].tail)
			{
				arr[k++] = que[m].data[que[m].head++];
			}
		}

		for (int n = 0; n < 10; ++n)
		{
			que[n].head = que[n].tail = 0;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		free(que[i].data);
	}
}