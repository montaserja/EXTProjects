#include"scheduler.h"

void Scheduler::run()
{
	ITask* min =*(tasks.begin());
	while(true)
	{
		for (std::vector<ITask*>::iterator it = tasks.begin() ; it != tasks.end(); ++it)
		{
			if((*it)->getNextRunPeriod() < min->getNextRunPeriod()){
				min = *it;
			}
			
		}
		
		// add time to this class and check if the time= min time then to start min run
		//if(min->getNextRunPeriod() == )
	}
}
