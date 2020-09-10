#ifndef __BIRD_H__
#define __BIRD_H__

#include"animal.h"
#include<iostream>
#include <sstream>
using std::cout;
using std::endl;

class Bird: public Animal
{
	public :
		inline Bird(const String&);
		inline ~Bird();
		virtual const unsigned short int& getHeight() const=0;
		virtual const float& getWingSpan() const=0;
		String print_children_Details() const;
};

inline Bird::Bird(const String& name):Animal(name){}
					
inline Bird::~Bird(){}

inline String Bird::print_children_Details() const
{
	std::stringstream ss;
	ss << "\nHeight : " << getHeight()
		<< "\nWing span : " << getWingSpan();
	String str_to_return=ss.str().c_str();
	return  str_to_return ;
}



#endif /* __BIRD_H__ */
