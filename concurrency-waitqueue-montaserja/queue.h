#ifndef __QUEUE_H__
#define __QUEUE_H__


#include <pthread.h>
#include <queue>
#include<iostream>

template <class T>
class waitQueue
{
	public:
		waitQueue(unsigned int size):m_size(size){
			pthread_mutex_init(&lock,NULL);
			pthread_cond_init(&cond,NULL);
		};
		void push(T data);
		
		T pop();
	private:
		unsigned int m_size;
		std::queue<T> m_queue;
		pthread_mutex_t lock;
		pthread_cond_t cond;
};

template <class T>
inline void waitQueue<T>::push(T data)
{
	pthread_mutex_lock(&lock);
	if(m_size == m_queue.size())
	{
		std::cout << "waiting int push func" <<std::endl;
		pthread_cond_wait(&cond , &lock);
	}
	else if(m_queue.size() == 0)
	{
		std::cout << "send signal push func" <<std::endl;
		m_queue.push(data);
		pthread_cond_signal(&cond);
	}else
	{
		m_queue.push(data);
		pthread_cond_signal(&cond);
	}
	pthread_mutex_unlock(&lock);
}

template <class T>
inline T waitQueue<T>::pop()
{
	pthread_mutex_lock(&lock);
	T temp ;
	if(m_queue.size() == 0)
	{
		std::cout << "waiting int pop func" <<std::endl;
		pthread_cond_wait(&cond , &lock);
	}
	else if(m_size == m_queue.size())
	{
		std::cout << "send signal pop func" <<std::endl;
		temp = m_queue.front();
		m_queue.pop();
		pthread_cond_signal(&cond);
	}else{
	temp = m_queue.front();
	m_queue.pop();
	pthread_cond_signal(&cond);
	}
	pthread_mutex_unlock(&lock);
	
	return temp;
}

#endif /* __QUEUE_H__ */

















