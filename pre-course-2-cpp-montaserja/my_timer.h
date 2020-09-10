#ifndef MY_TIMER_H_
#define MY_TIMER_H_

#include <cstdio>
#include <iostream>
#include <unistd.h>
#include "my_time.h"
#include <string>
#include "msg_printer.h"

using namespace std;
class Timer {
	static const string minute_input[];
	static const string hours_input[];
	Time target;
	Time clock;
	MsgPrinter* pprinter;

public:
	Timer(Time t, MsgPrinter* mp);
	//virtual ~Timer();
	void check_clock();
	void check_min_hours(char* S,unsigned int increments);

	inline void tick(){
		clock+=1;
		check_clock();
	}

	inline void tick(unsigned int amount){
		clock+=amount;
		check_clock();

	}
	
	inline void tick(char* S){
		
		check_min_hours(S,1);
		check_clock();

	}
	inline void tick(char* S,unsigned int increments){
		
		check_min_hours(S,increments);
		check_clock();

	}
	
	

};
/*void run_timer_1();
void run_timer_2();*/
#endif 
