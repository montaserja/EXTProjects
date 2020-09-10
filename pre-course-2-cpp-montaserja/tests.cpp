


#include "tests.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <list>

#include <unistd.h>
void run_timer_1(){
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
}

void run_timer_3(){
	// we can define the printers on the stack to avoid freeing them

	MsgPrinter* printers[3];
	
	printers[0] = new MsgPrinter("this is the emessage");
	printers[1]= new MsgPrinterSurrounding("Surrounded",
			"---Start---","---End---");
	printers[2]= new MsgPrinterMultipleSurrounding("Really Surrounded",
			">>>>>>>","<<<<<<<", 3);


	Timer t1(Time(0,0,10),printers[0]);
	Timer t2(Time(0,0,15),printers[1]);
	Timer t3(Time(0,0,20),printers[1]);
	Timer t4(Time(0,0,25),printers[2]);
	Timer t5(Time(0,0,30),printers[2]);

	for (int i=0 ; i<40 ;i++){
		std::cout << "iteration: "<< i <<std::endl;
		t1.tick();
		t2.tick();
		t3.tick();
		t4.tick();
		t5.tick();

	}
	for (int i =0; i<3;i++)
		delete printers[i];

}
void run_timer_4(){
	std::cout <<"testing the list with iterator"<<std::endl;
	MsgPrinter* printers[3];
	MsgPrinter* printer= new MsgPrinter("this is the message");
	if(!printer){
		perror("no memory");
	}
	printers[0] = printer;
	printers[1]= new MsgPrinterSurrounding("Surrounded",
			"---Start---","---End---");
	printers[2]= new MsgPrinterMultipleSurrounding("Really Surrounded",
			">>>>>>>","<<<<<<<", 3);

	std::list<Timer> timers;

	timers.insert(timers.begin(),Timer(Time(0,0,10),printers[0]));
	timers.insert(timers.begin(),Timer(Time(0,0,15),printers[1]));
	timers.insert(timers.begin(),Timer(Time(0,0,20),printers[1]));
	timers.insert(timers.begin(),Timer(Time(0,0,25),printers[2]));
	timers.insert(timers.begin(),Timer(Time(0,0,30),printers[2]));





	for (int i=0 ; i<40 ;i++){
		std::cout << "iteration: "<< i <<std::endl;
		for(std::list<Timer>::iterator i = timers.begin();
				i != timers.end(); ++i){
				i->tick();
		}

	}

	for (int i =0; i<3;i++)
		delete(printers[i]);

}
void custom_test(){
	try{
			Time t2 (100,5,100);
		} catch (std::exception& e){
			std::cout << "catching exeption"<<std::endl;
		}
		std::cout << "!!!Helddlo World!!!" << std::endl; // prints !!!Hello World!
		char a = 85;
		std::cout << a << std::endl;
		std::string asss ="dd";
		std::cout << asss <<std::endl;
		Time t (100,5,10);
		std::cout <<"time before "<< t.get_as_string(false) <<std::endl;
		t += 1000;
		std::cout <<"time after "<< t.get_as_string(false) <<std::endl;

		char hhh[50];
		std::sprintf(hhh,"hello \n");
		MsgPrinter mp(hhh) ;
		Timer t3(t,&mp);

}


