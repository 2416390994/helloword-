#include<iostream>
using namespace std;
class A
{
public:
	static volatile int* sss()
	{
		if (p == nullptr)
		{
			//¼ÓËø
			if (p == nullptr)
			{
				p = new int(10);
			}
			//½âËø
		}
		return p;     
	}
private:
	volatile static int* p;
};
volatile int* A::p = nullptr;

#include<stdio.h>                                                                                                                                            
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<vector>
#include<iostream>

using namespace std;
pthread_cond_t cond;
pthread_mutex_t mutex;
vector<int> vec;

void* func1(void* argv)
{
	(void)argv;
	int count = 0;
	while (1)
	{
		pthread_mutex_lock(&mutex);
		vec.push_back(++count);
		usleep(12345);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
	}
	return NULL;
}
void* func2(void* argv)
{
	(void)argv;
	while (1)
	{
		pthread_mutex_lock(&mutex);
		if (vec.empty())
		{
			pthread_cond_wait(&cond, &mutex);
		}
		vec.pop_back();
		usleep(12345);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main()
{
	pthread_t tid[4];
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);


	pthread_create(&tid[0], NULL, func1, NULL);
	pthread_create(&tid[1], NULL, func1, NULL);
	pthread_create(&tid[2], NULL, func2, NULL);
	pthread_create(&tid[3], NULL, func2, NULL);

	for (int i = 0; i < 4; ++i)
	{
		pthread_join(tid[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return 0;
}



