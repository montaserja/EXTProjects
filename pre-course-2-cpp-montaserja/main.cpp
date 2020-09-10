//#include "my_time.h"
#include "my_timer.h"
#include "msg_printer.h"
#include "tests.h"

using namespace std;
int main(){


	cout<<"--------------------RUN TIMER 1--------------------"<<endl;
	run_timer_1();
	cout<<"--------------------RUN TIMER 2--------------------"<<endl;
	run_timer_2();
	cout<<"--------------------RUN TIMER 3--------------------"<<endl;
	run_timer_3();
	cout<<"--------------------RUN TIMER 4--------------------"<<endl;
	run_timer_4();
	cout<<"--------------------RUN TIMER CUSTOM--------------------"<<endl;
	custom_test();

	/*try	{
		Time t1(60);
		Time t2(3601);
		t2+=7;
		//printf("%ld\n",t3.get_seconds());
		print(t2);
		printf("%d\n",t2!=t1);
		run_timer_2();
		}
	catch(exception const & ex){
	cerr<<ex.what()<<"\n";
	}*/
return 0;
}
