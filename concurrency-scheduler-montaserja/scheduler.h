#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include<vector>
#include"ITask.h"

// add stop 

class Scheduler {
	public:
		Scheduler();
		~Scheduler();
		void add_task(ITask*);
		void remove_task(ITask*);
		void run();
	private:
		std::vector<ITask*> tasks;

};

inline Scheduler::Scheduler(){}

inline Scheduler::~Scheduler(){}

inline void Scheduler::add_task(ITask* task)
{
	tasks.push_back(task);
}

inline void Scheduler::remove_task(ITask* task)
{
	int i=0;
	for (std::vector<ITask*>::iterator it = tasks.begin() ; it != tasks.end(); ++it)
	{
		if(*it == task){
			tasks.erase(tasks.begin()+i);
			break;
		}
		++i;
	}
}


#endif /* __SCHEDULER_H__ */
