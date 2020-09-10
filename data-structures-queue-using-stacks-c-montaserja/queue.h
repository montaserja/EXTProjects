#ifndef __QUEUE_H__
#define __QUEUE_H__

#include"stack.h"

class Queue
{
	public:
		Queue(int size):size(size),items(0),s1(new Stack(size)),s2(new Stack(size)){}
		~Queue(){
			delete s1;
			delete s2;
		};
		int pop();
		bool push(int x);
		bool isEmpty();
		void reverse_queue();
	
	private:
		int size;
		int items;
		Stack *s1,*s2;
	
		

};


inline bool Queue::isEmpty()
{
	if(s1->isEmpty() && s2->isEmpty())
	{
		return true;
	}
	return false;
}

inline void Queue::reverse_queue(){
	int x;
	while(!s1->isEmpty())
	{
		x = s1->pop();
		s2->push(x);
	}
}
	
inline int Queue::pop()
{
	if (s2->isEmpty())
	{
		if(!s1->isEmpty())
			reverse_queue();
		else
			return -1;
	}
	--items;
	return s2->pop();
}

inline bool Queue::push(int x)
{
	if(items >= size)
	{
		std::cout << "Queue over flow" <<std::endl;
		return false;
	}
	if(s1->isEmpty())
		if(!s2->isEmpty())
			reverse_queue();
	++items;
	s1->push(x);
	return true;
}


#endif /* __QUEUE_H__ */
