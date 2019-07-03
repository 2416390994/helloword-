//��
//1.�ѵĸ���---->����-->���ն�������˳��洢��ʽ�洢��һά�����У���������ڵ㣬����亢�Ӵ��ڣ��ýڵ���ֵ���
//С���亢�ӽ��
//�ѵ�����
//�Ѷ�Ԫ��һ�������С��������ѣ�С�ѣ�
//�ѵĻ�������
//���һ����ȫ��������N����㣬��ô���ĸ߶�����2Ϊ��N�Ķ���
//��������Ķ���������=0�Ľ��=��=2�Ľ��+1��(  n0=n2+1  );
//�����ѵ�ʱ�临�Ӷ�Nlog�Զ�Ϊ�׵�n�Σ������ɾ����ʱ�临�Ӷ�log�Զ�Ϊ�׵�n�Ρ�

//27��15��34��25��28��19��65��49��18��37
//�öѽ�������
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
//1.����
	int last = ((size - 2) >> 1);
	for (; last >= 0; --last)
		HeapAdjust(array, size, last);//���µ���
//2.����
	int end = size - 1;
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}//�����еĻ������ܰ���
//���-->����
//С��-->����


//����һ�������㷨���ȶ���
//�ڲ������ⲿ���򣬿���Ҫ�ŵ������Ƿ�Ҫһ���Լ��ص��ڴ���
//���������㷨����������ֱ������ϣ�����򣩣�ѡ������ѡ�����򣬶����򣩣���������ð�����򣬿������򣩣��ݹ����򣨹鲢����


//��������(ֱ������)
void InsertSort(int *array, int size)
{
	int i = 1;
	for (i; i < size; i++)
	{
		int key = array[i];
		int end = i - 1;
		//����Ԫ��
		while (key < arrar[end] && end >= 0)
		{
			array[end + 1] = array[end];
			end--;
		}
		//����
		array[end + 1] = key;
	}
}
//���������ʺ���С�����ҽӽ����������
//�������һ����������� ����������ʹ�ò��������˼��������򣨷��飩
//ʲô�нӽ�����---->���Ԫ�ؾ�������С��Ԫ�ؾ���ǰ������С�����м�


//��������ϣ������    ����Ԫ�ؽ���������ϣ�������ȶ�
void ShellSort(int *array,int size)
{
	int gap = size;                
   while (gap > 1)
	{
	 gap = gap / 3 + 1;             //���gap���Ĳ��ã���Ӱ��ϣ���������ܣ���gap���������gap=gap/3+1��
	 int i = gap;               
	 for (i; i < size; i++)
	  {
		int key = array[i];
		int end = i - gap;
		//����Ԫ��
		while (key < arrar[end] && end >= 0)
		{
			array[end + gap] = array[end];
			end -= gap;
		}
		//����
		array[end + gap] = key;
	  }
	 //gap-=1;
	}
}

//ѡ������ѡ�����򣬶�����
//ѡ������
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

//ѡ�������Ż�(�����Ǹ�����ֻ��һ������һ��Ԫ�أ��Ż���Ĵ���һ������һ�����ģ�һ����С�� ��ʹЧ�ʼӿ�)
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
			MinPos = MaxPos;          //�����һ���ж�������жϣ��жϵ���һ��������������ֵ�����󣬸ı���ԭ����Сֵ����ǵ�λ�ã�����������Ҫ���±��
		if (MinPos != begin)
			Swap(&array[MinPos], &array[begin]);
		begin++;
		end--;
	}
}
//ѡ�������ȶ�
void HeapSort(int *array, int size)
{

}
