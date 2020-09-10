#include "msg_printer.h"

using namespace std;


MsgPrinter::MsgPrinter(std::string m): message(m) {
}

MsgPrinter::~MsgPrinter() {
	cout << "End of MsgPrinter:"<< message << endl;
}

void MsgPrinter::print(){
	cout << "Message:"<< message << endl;
}

MsgPrinterSurrounding::MsgPrinterSurrounding(const std::string msg):MsgPrinter(msg),before(0),after(0){


}

MsgPrinterSurrounding::MsgPrinterSurrounding(const std::string msg,const char* before_msg,const char* after_msg):MsgPrinter(msg){
	before=new char[strlen(before_msg)+1];
	strcpy(before,before_msg);
	after=new char[strlen(after_msg)+1];
	strcpy(after,after_msg);
}

MsgPrinterSurrounding::~MsgPrinterSurrounding(){
	delete(before);
	delete(after);
	cout << "End of MsgPrinterSorrounding:";
	MsgPrinter::print();
}


MsgPrinterSurrounding::MsgPrinterSurrounding(const MsgPrinterSurrounding &msgP2):MsgPrinter(msgP2.message),before(msgP2.before),after(msgP2.after){}


void MsgPrinterSurrounding::print_before(){
	cout << *before << endl;
}



void MsgPrinterSurrounding::print_after(){
	cout << *after << endl;
}

void MsgPrinterSurrounding::print(){
	print_before();
	MsgPrinter::print();
	print_after();
}

MsgPrinterSurrounding MsgPrinterSurrounding::operator=(const MsgPrinterSurrounding &msgP2){
return *(new  MsgPrinterSurrounding(msgP2));
}

MsgPrinterMultipleSurrounding::MsgPrinterMultipleSurrounding(const std::string msg,unsigned char times):
						MsgPrinterSurrounding(msg),times(times){}

MsgPrinterMultipleSurrounding::MsgPrinterMultipleSurrounding
			(const std::string msg,const char* before_msg,const char* after_msg,unsigned char times):
			MsgPrinterSurrounding(msg,before_msg,after_msg),
			times(times){}

MsgPrinterMultipleSurrounding::~MsgPrinterMultipleSurrounding(){
	cout<<"End of MsgPrinterMultipleSurrounding:"<< message << endl;
}

void MsgPrinterMultipleSurrounding::set_times(unsigned char times){
MsgPrinterMultipleSurrounding::times=times;
}

unsigned char MsgPrinterMultipleSurrounding::get_times()const{
return MsgPrinterMultipleSurrounding::times;
}

void MsgPrinterMultipleSurrounding::print_before(){
	for(int i=0;i<times;i++){
		MsgPrinterSurrounding::print_before();
	}
}


void MsgPrinterMultipleSurrounding::print_after(){
	for(int i=0;i<times;i++){
		MsgPrinterSurrounding::print_after();
	}
}
















































