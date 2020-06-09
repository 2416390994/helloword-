#include<iostream>
#include<vector>
using namespace std;
class A
{
public:
	A()
	:head(0)
	,tail(0)
	, count(10)
	, size(0)
	{
		vec.resize(10);
	}

	bool Push(int val)
	{
		if (size == 10)
		{
			return false;
		}
		vec[tail] = val;
		cout << "vec[" << tail << "]" << "=" << val << endl;
		tail = (tail + 1) % count;
		size++;
		return true;
	}

	bool Pop()
	{
		if (size == 0)
		{
			return false;
		}
		size--;
		head = (head + 1) % count;
		cout << size << endl;
	}
private:
	vector<int> vec;
	int head;
	int tail;
	int size;
	int count;
};
int main()
{
	A a;
	a.Push(1);
	a.Pop();
	a.Push(2);
	a.Push(3);
	a.Push(4);
	a.Push(5);
	a.Push(6);
	a.Push(7);
	a.Push(8);
	a.Push(9);
	a.Push(10);
	a.Pop();
	a.Pop();
	a.Pop();
	a.Pop();
	a.Pop();
	a.Pop();
	a.Pop();
	a.Pop();
	a.Pop();
	a.Pop();
	return 0;
}





///////////////////////////////////////////
#include<iostream>
#include<vector>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
using namespace std;

pthread_mutex_t mutex;
pthread_cond_t cond1;
pthread_cond_t cond2;


template<class T>
class Ring_Blocking_Queue
{
public:
	Ring_Blocking_Queue(int val)
		:Count(val)
		, Head(0)
		, Tail(0)
		, Queue_Size(0)
	{
		_queue.resize(val);
		pthread_mutex_init(&mutex, NULL);
		pthread_cond_init(&cond1, NULL);
		pthread_cond_init(&cond2, NULL);
	}

	~Ring_Blocking_Queue()
	{
		pthread_mutex_destroy(&mutex);
		pthread_cond_destroy(&cond1);
		pthread_cond_destroy(&cond2);
	}

	void Push(T& val)
	{
		pthread_mutex_lock(&mutex);
		if (Queue_Size == Count)
		{
			pthread_cond_wait(&cond1, &mutex);
		}
		_queue[Tail] = val;
		Queue_Size++;
		Tail = (Tail + 1) % Count;
		pthread_mutex_unlock(&mutex);
		if (Queue_Size == 1)
		{
			pthread_cond_signal(&cond2);
		}
	}

	void  Pop(T& p)
	{
		pthread_mutex_lock(&mutex);
		if (Queue_Size == 0)
		{
			pthread_cond_wait(&cond2, &mutex);
		}
		p = _queue[Head];
		Queue_Size--;
		Head = (Head + 1) % Count;
		pthread_mutex_unlock(&mutex);
		if (Queue_Size == (Count - 1))
		{
			pthread_cond_signal(&cond1);
		}
	}
private:
	int Queue_Size;  //环形队列的有效元素
	int Head;
	int Tail;
	int Count;
	vector<T> _queue;
};

#include"环形阻塞队列.cpp"    

class Task
{
public:
	virtual ~Task()
	{}

	virtual void RUN()
	{}
};


class MyTask :public Task
{
public:
	MyTask(int id)
		:_id(id)
	{}

	~MyTask()
	{}

	void RUN()
	{
		cout << "id = " << _id << endl;
	}

private:
	int _id;
};

class Pthread_Pool
{
public:
	Pthread_Pool(int n)
		:work_pthread_size(n)
		, pool(20)
	{
		for (int i = 0; i < n; ++i)
		{
			pthread_t tid;
			pthread_create(&tid, NULL, Perform_Task, this);
			pthread_tid.push_back(tid);
		}
	}

	~Pthread_Pool()
	{
		for (size_t i = 0; i < pthread_tid.size(); ++i)
		{
			pthread_join(pthread_tid[i], NULL);
		}
	}

	void ADD(Task* task)
	{
		pool.Push(task);
	}

private:
	int work_pthread_size;
	vector<pthread_t> pthread_tid;
	Ring_Blocking_Queue<Task*> pool;
	static void* Perform_Task(void* arg)
	{
		Pthread_Pool* temp = (Pthread_Pool*)arg;
		while (true)
		{
			Task* task = nullptr;
			temp->pool.Pop(task);
			task->RUN();
			delete task;
		}
	}
};

int main()
{
	Pthread_Pool  pool(10);
	cout << "线程池创建成功，并且往里面塞了十个工作线程" << endl;

	for (int i = 0; i < 20; ++i)
	{
		pool.ADD(new MyTask(i));
	}
	return 0;
}

