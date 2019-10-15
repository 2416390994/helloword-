#include<iostream>
using namespace std;
//class MyCircularQueue {
//public:
//	/** Initialize your data structure here. Set the size of the queue to be k. */
//	//构造一个空的队列，使用的是数组进行构造的
//	MyCircularQueue(int k) {
//		array = new int[k];
//		size = 0;
//		front = 0;
//		rear = 0;
//		capacity = k;
//	}
//	/** Insert an element into the circular queue. Return true if the operation is successful. */
//	//插入数据，这里的插入肯定是尾插
//	bool enQueue(int value) {
//		if (size == capacity)  //假如满了，则返回错
//			return false;
//		array[rear] = value;   //没满的话则插入元素
//		rear = (rear + 1) % capacity;
//		size++;
//		return true;
//	}
//	//弹出
//	/** Delete an element from the circular queue. Return true if the operation is successful. */
//	bool deQueue() {
//		if (size == 0)
//			return false;
//		front = (front + 1) % capacity;   //弹出队首元素
//		size--;
//		return true;
//	}
//	//查看队首元素
//	/** Get the front item from the queue. */
//	int Front() {
//		if (size == 0)   //加入为空返回-1，这里的话主要看要求
//			return -1;
//		return array[front];
//	}
//	//查看队尾元素
//	/** Get the last item from the queue. */
//	int Rear() {
//		if (size == 0)
//			return -1;
//		return array[(rear + capacity - 1) % capacity];
//	}
//	//判空
//	/** Checks whether the circular queue is empty or not. */
//	bool isEmpty() {
//		return size == 0;
//	}
//	//判断是否满了
//	/** Checks whether the circular queue is full or not. */
//	bool isFull() {
//		return size == capacity;
//	}
//
//	int* array;   //队列的指针
//	int size;   //有效数字的长度
//	int capacity;   //队列的容量
//	int rear;  //标记的是下一个待插入的空的位置
//	int front; // 标记的是下一个待弹出的位置
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