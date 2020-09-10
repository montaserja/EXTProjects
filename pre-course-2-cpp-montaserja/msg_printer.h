#ifndef MSG_PRINTER_H_
#define MSG_PRINTER_H_


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <exception>
#include <cstdio>
class MsgPrinter {
protected:
	 std::string message;
public:
	MsgPrinter(std::string message);
	virtual void print();
	virtual ~MsgPrinter();
	
};

class MsgPrinterSurrounding : public MsgPrinter{
	protected:
		char* before;
		char* after;
		virtual void print_before();
		void print_after();
	public:
		MsgPrinterSurrounding(const std::string msg);
		MsgPrinterSurrounding(const std::string msg,const char* before_msg,const char* after_msg);
		void print();
		virtual ~MsgPrinterSurrounding();
		MsgPrinterSurrounding(const MsgPrinterSurrounding &msgP2);
		MsgPrinterSurrounding operator=(const MsgPrinterSurrounding &msgP2);
};

class MsgPrinterMultipleSurrounding:public MsgPrinterSurrounding{
	unsigned char times;
	
	public:
		MsgPrinterMultipleSurrounding(const std::string msg,unsigned char times=2);
		MsgPrinterMultipleSurrounding(const std::string msg,const char* before_msg,const char* after_msg,unsigned char times=2);
		~MsgPrinterMultipleSurrounding();
		void set_times(unsigned char times);
		unsigned char get_times()const;
		void print_before();
		void print_after();
};


#endif





















