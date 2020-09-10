#ifndef __ITASK_H__
#define __ITASK_H__

#include"time.h"
#include<iostream>
#include <unistd.h>

class ITask
{
	public:
   		virtual void run() = 0;
  	 	virtual unsigned long getNextRunPeriod() = 0; // in millisecondss
};


class abstarctTask: public ITask
{
	public:
	abstarctTask(int times,Time startTime,unsigned int period):m_times(times),nextTime(startTime),period(period){};
	void run(){
		runImplementation();
		set_times();
	};
	virtual void runImplementation();
	virtual void set_times(){
		
		--m_times;
		nextTime+=period;
	};
	virtual unsigned long getNextRunPeriod(){
		if(m_times <= 0)
		{
			return -1;
		}
		return nextTime.get_time();
	};
	
	private:
		int m_times;
		Time nextTime;
		unsigned int period;
};

class helloTask: public abstarctTask
{
	public:
		helloTask(int times,Time startTime,unsigned int period):abstarctTask(times,startTime,period){};
		void runImplementation(){
			std::cout << "HELLO" << std::endl;
			sleep(1);
		};
	
};

class byeTask: public abstarctTask
{
	public:
		byeTask(int times,Time startTime,unsigned int period):abstarctTask(times,startTime,period){};
		void runImplementation(){
			std::cout << "BYE!!" << std::endl;
			sleep(1);
		};
	
};

#endif /* __ITASK_H__ */
