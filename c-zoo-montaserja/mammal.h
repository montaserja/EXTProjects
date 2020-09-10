#ifndef __MAMMAL_H__
#define __MAMMAL_H__

#include"animal.h"
#include<iostream>
#include"mammalInterface.h"
#include <sstream>
using std::cout;
using std::endl;

class Mammal : public Animal,public MammalInterface
{
	public :
		Mammal(const String&);
		virtual inline ~Mammal();
		String print_children_Details() const;
};

inline Mammal::Mammal(const String& name):Animal(name){}
	
inline Mammal::~Mammal(){}

inline String Mammal::print_children_Details() const
{
	std::stringstream ss;
	ss << "\npregnancy duration : " << static_cast<int>(getPregnancyDuration())
		<< "\nyoung born : " << static_cast<int>(getNumberYoungBorn());
	String str_to_return=ss.str().c_str();
	return  str_to_return ;
}
#endif /* __MAMMAL_H__ */
