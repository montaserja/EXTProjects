
#ifndef MY_TIME_H_
#define MY_TIME_H_

#include <string>
#include <iostream>
#include <exception>
#include <stdio.h>
#define maxHours 100000
#define minValue 0
#define maxMS 59




	class invalid_argumen: public std::exception {
		const char* what() const throw()
		  {
			return "My exception";
		  }
	};

	
    class Time
    {
    private:
    unsigned long int hours;
	unsigned char minutes;
	unsigned char seconds;
	void cal(unsigned long seconds);
    public:
    	Time(unsigned long int hours,unsigned char minutes,unsigned char seconds);
    	Time(unsigned long seconds);
    	std::string get_as_string (bool is_using_days)const ;
    	unsigned long int get_seconds();
    	Time operator +(Time t2);
    	Time operator +(unsigned long seconds);
    	void operator +=(unsigned long seconds);
    	bool operator ==(Time t2);
    	bool operator <=(Time t2);
    	bool operator >=(Time t2);
    	bool operator !=(Time t2);
    	bool operator <(Time t2);
    	bool operator >(Time t2);
    	friend std::ostream & operator <<(std::ostream &out, const Time &t);
    	
    	
    };

	void print(const Time t);
	

#endif 

