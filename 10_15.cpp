#include<iostream>
using namespace std;
//class MyCircularQueue {
//public:
//	/** Initialize your data structure here. Set the size of the queue to be k. */
//	//����һ���յĶ��У�ʹ�õ���������й����
//	MyCircularQueue(int k) {
//		array = new int[k];
//		size = 0;
//		front = 0;
//		rear = 0;
//		capacity = k;
//	}
//	/** Insert an element into the circular queue. Return true if the operation is successful. */
//	//�������ݣ�����Ĳ���϶���β��
//	bool enQueue(int value) {
//		if (size == capacity)  //�������ˣ��򷵻ش�
//			return false;
//		array[rear] = value;   //û���Ļ������Ԫ��
//		rear = (rear + 1) % capacity;
//		size++;
//		return true;
//	}
//	//����
//	/** Delete an element from the circular queue. Return true if the operation is successful. */
//	bool deQueue() {
//		if (size == 0)
//			return false;
//		front = (front + 1) % capacity;   //��������Ԫ��
//		size--;
//		return true;
//	}
//	//�鿴����Ԫ��
//	/** Get the front item from the queue. */
//	int Front() {
//		if (size == 0)   //����Ϊ�շ���-1������Ļ���Ҫ��Ҫ��
//			return -1;
//		return array[front];
//	}
//	//�鿴��βԪ��
//	/** Get the last item from the queue. */
//	int Rear() {
//		if (size == 0)
//			return -1;
//		return array[(rear + capacity - 1) % capacity];
//	}
//	//�п�
//	/** Checks whether the circular queue is empty or not. */
//	bool isEmpty() {
//		return size == 0;
//	}
//	//�ж��Ƿ�����
//	/** Checks whether the circular queue is full or not. */
//	bool isFull() {
//		return size == capacity;
//	}
//
//	int* array;   //���е�ָ��
//	int size;   //��Ч���ֵĳ���
//	int capacity;   //���е�����
//	int rear;  //��ǵ�����һ��������Ŀյ�λ��
//	int front; // ��ǵ�����һ����������λ��
//};
//#include<string>
//void print(string s,int from,int to)
//{
//	if (from == to)
//	{
//		cout << s << endl;
//		return;
//	}
//	for (int i = from; i < s.size(); ++i)
//	{
//		swap(s[i], s[from]);
//		print(s,from+1,to);
//		swap(s[i], s[from]);
//	}
//}
//int main()
//{
//	string s("abc");
//	string v;
//	/*v = s.substr(1);
//	cout << v << endl;*/
//	for (int i = 0; i < s.size(); ++i)
//	{
//		v = s.substr(i);
//		print(v, 0, v.size());
//	}
//	return 0;
//}
int main()
{
	
	
	return 0;
}