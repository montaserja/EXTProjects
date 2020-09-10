#ifndef __FACTORY_H__
#define __FACTORY_H__

#include"producer.h"
#include<pthread.h>
#include"box.h"
#include"consumer.h"
#include<iostream>
#include<unistd.h>


//pthread_mutex_t producers_mutex =PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t consumers_mutex =PTHREAD_MUTEX_INITIALIZER;


class Factory
{
	public:
		Factory(int producers,int consumers,Box *box):
						m_producers(producers),m_consumers(consumers),m_box(box){}
						
		void start_threads();

	private:
		int m_producers;
		int m_consumers;
		Box *m_box;
		
		
		static void* produce(void* p)
		{
			Producer producer = *((Producer*) p);
			bool stop = false;
			while(!stop){
				
				if(!producer.produce())
					stop=true;
				
			}
			delete((Producer*)p);
			return NULL;
		}
		static void* consume(void* c)
		{
			Consumer consumer = *((Consumer*) c);
			bool stop = false;
			while(!stop)
			{
				
				if(!consumer.consume())
					stop=true;
				
			}
			delete((Consumer*)c);
			return NULL;
		}

};

inline void Factory::start_threads()
{
	int i=0;
	pthread_t producers_threads[3];
	pthread_t consumers_threads[4];
	
	for(i=0;i<3;++i)
	{
		pthread_create(&producers_threads[i],NULL,produce,new Producer(40,m_box));	
	}
	
	for(i=0;i<4;++i)
	{
		//Consumer c(20,m_box);
		pthread_create(&consumers_threads[i],NULL,consume,new Consumer(30,m_box));
		//pthread_join(consumers_threads[i],NULL);
	}
	
	
	// in another func
	for(i = 0;i<3;++i)
	{
		pthread_join(producers_threads[i],NULL);
	}
	
	
	for(i=0;i<4;++i)
	{
		pthread_join(consumers_threads[i],NULL);
	}
}

#endif /* __FACTORY_H__ */








