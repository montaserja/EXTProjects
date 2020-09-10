#ifndef __FISH_H__
#define __FISH_H__

#include"animal.h"
#include<iostream>
#include"fishInterface.h"
#include<sstream>
using std::cout;
using std::endl;

class Fish: public Animal,public FishInterface
{
	public :
		Fish(const String&);
		~Fish();
		String print_children_Details() const;
};

inline Fish::Fish(const String& name):Animal(name){}
			
inline Fish::~Fish(){}

inline String Fish::print_children_Details() const
{
	std::stringstream ss;
	ss << "\nLowest depth : " << static_cast<int>(getLowestDepth());
	String str_to_return=ss.str().c_str();
	return  str_to_return ;
}

#endif
