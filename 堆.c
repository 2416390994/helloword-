//堆
//1.堆的概念---->序列-->按照二叉树的顺序存储方式存储到一维数组中，对于任意节点，如果其孩子存在，该节点中值域均
//小于其孩子结点
//堆的特性
//堆顶元素一定最大（最小），（大堆，小堆）
//堆的基本操作
//如果一个完全二叉树有N个结点，那么树的高度是以2为底N的对数
//对于任意的二叉树，度=0的结点=度=2的结点+1；(  n0=n2+1  );
//创建堆的时间复杂度Nlog以二为底的n次，插入和删除的时间复杂度log以二为底的n次。

//27，15，34，25，28，19，65，49，18，37
//用堆进行排序
void HeapAdjust(int *array, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&array[child + 1] < array[child])
			child = child + 1;

		if (array[child] < array[parent])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
void HeapSort(int *array, int size)
{
//1.建堆
	int last = ((size - 2) >> 1);
	for (; last >= 0; --last)
		HeapAdjust(array, size, last);//向下调整
//2.排序
	int end = size - 1;
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}//基础中的基础，很爱考
//大堆-->升序
//小堆-->降序


//衡量一个排序算法的稳定性
//内部排序，外部排序，看需要排的序列是否要一次性加载到内存中
//常见排序算法：插入排序（直接排序，希尔排序），选择排序（选择排序，堆排序），交换排序（冒泡排序，快速排序），递归排序（归并排序）


//插入排序(直接排序)
void InsertSort(int *array, int size)
{
	int i = 1;
	for (i; i < size; i++)
	{
		int key = array[i];
		int end = i - 1;
		//搬移元素
		while (key < arrar[end] && end >= 0)
		{
			array[end + 1] = array[end];
			end--;
		}
		//插入
		array[end + 1] = key;
	}
}
//插入排序适合量小，并且接近有序的序列
//假如给你一个量大的序列 ，并且让你使用插入排序的思想进行排序（分组）
//什么叫接近有序---->大的元素尽量靠后，小的元素尽量前，不大不小的在中间


//插入排序（希尔排序）    隔着元素交换，所以希尔排序不稳定
void ShellSort(int *array,int size)
{
	int gap = size;                
   while (gap > 1)
	{
	 gap = gap / 3 + 1;             //如果gap给的不好，会影响希尔排序性能，那gap有人提出，gap=gap/3+1；
	 int i = gap;               
	 for (i; i < size; i++)
	  {
		int key = array[i];
		int end = i - gap;
		//搬移元素
		while (key < arrar[end] && end >= 0)
		{
			array[end + gap] = array[end];
			end -= gap;
		}
		//插入
		array[end + gap] = key;
	  }
	 //gap-=1;
	}
}

//选择排序（选择排序，堆排序）
//选择排序
void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


void SelectSort(int *array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int MaxPos = 0;
		int j = 1;
		for (j; j < size - i; ++j)
		{
			if (array[j]>array[MaxPos])
				MaxPos = j;
		}
		if (MasPos!=size-i-1)
		 Swap(&array[MaxPos], &array[size - i - 1]);
	}
}

//选择排序优化(上面那个排序只是一次性找一个元素，优化后的代码一次性找一个最大的，一个最小的 ，使效率加快)
void SelectSort_OP(int *array, int size)
{
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int MaxPos = begin;
		int MinPos = begin;
		int i = begin;
		while (i <= end)
		{
			if (array[i] > MaxPos)
				MaxPos = i;
			if (array[i] < MinPos)
				MinPos = i;
			i++;

		}
		if (MaxPos != end)
			Swap(&array[MaxPos], &array[end]);
		if (MinPos == end)
			MinPos = MaxPos;          //这个是一个判读，这个判断，判断的是一个特殊情况，最大值交换后，改变了原先最小值所标记的位置，所以这里需要重新标记
		if (MinPos != begin)
			Swap(&array[MinPos], &array[begin]);
		begin++;
		end--;
	}
}
//选择排序不稳定
void HeapSort(int *array, int size)
{

}
