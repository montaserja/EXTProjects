#include "my_timer.h"
#include "msg_printer.h"

using namespace std;

const string Timer::minute_input[]={"M","m", "Min", "min", "Minute","minute"};
const string Timer::hours_input[]={"H", "h", "Hour", "hour"};

Timer::Timer(Time t, MsgPrinter* mp): target(t), clock(0), pprinter (mp) {


}

void Timer::check_clock(){
	if(clock.get_seconds() > target.get_seconds())
		pprinter->print();
}

void Timer::check_min_hours(char* S,unsigned int increments){
	for(int i=0; i<5;i++){
		//printf("%d",Timer::minute_input[i]==S);
		if(Timer::minute_input[i]==S){
		clock+=(60*increments);
		return;	
		}
	}
	for(int i=0; i<5;i++){
		if(Timer::hours_input[i]==S){
		clock+=(3600*increments);
		return;	
		}
	}
	throw invalid_argumen();
}

/*void run_timer_1(){
	Time t(1,30,0);
	MsgPrinter mp("Hello World");
	Timer timer(t,&mp);
	for(int i=0;i<50;i++){
		printf("round %d\n",i);
		timer.tick((char*)"M",2);
	}
}

void run_timer_2(){
	Time t(7);
	MsgPrinter mp("Seven Seconds");
	Timer timer(t,&mp);
	for(int i=0;i<10;i++){
		sleep(1);
		printf("round %d\n",i);
		timer.tick();
	}
}*/










