#include"queue.h"
#include<pthread.h>
#include<iostream>
#include<unistd.h>

#define pushers_num 3
#define popers_num 4
#define amount 120
#define queue_size 6


template<class T=int>
struct threads_data
{
	int thread_id;
	waitQueue<T>* q;
};

void* pop_threads(void* d)
{
	threads_data<int>& data = *((threads_data<int>*) d);
	int temp;
	for(int i=0 ;i<(amount / popers_num) ; ++i){
		temp = (int)data.q->pop();
		std::cout << "thread "<< data.thread_id << " poped " << temp <<std::endl;
	}
	return NULL;
}

void* push_threads(void* d)
{
	threads_data<int>& data = *((threads_data<int>*) d);
	for(int i=0 ;i<(amount / pushers_num)  ; ++i){
		data.q->push(i);
		std::cout << "thread "<< data.thread_id << " pushed " << i << std::endl;
	}
	
	return NULL;
}

int main()
{
	pthread_t pushers[pushers_num + popers_num];
	threads_data<int> data[pushers_num + popers_num];
	waitQueue<int> my_queue(queue_size);
	for(int i=0 ;i<(pushers_num + popers_num) ;++i)
	{
		data[i].thread_id = i;
		data[i].q = &my_queue;
	}
	
	for(int i=0 ; i<pushers_num ;++i)
	{
		pthread_create(&pushers[i],NULL,push_threads,&data[i]);	
	}
	for(int i=pushers_num ; i<(pushers_num + popers_num) ;++i)
	{
		pthread_create(&pushers[i],NULL,pop_threads,&data[i]);	
	}
	
	for(int i=0 ; i<(pushers_num + popers_num) ;++i)
	{
		pthread_join(pushers[i],NULL);	
	}
	
	
	
	return 0;
}









