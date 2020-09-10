#ifndef __WHALE_H__
#define __WHALE_H__

#include"animal.h"
#include<iostream>
#include"mammalInterface.h"
#include"fishInterface.h"
#include <sstream>
using std::cout;
using std::endl;

class Whale : public Animal,public MammalInterface,public FishInterface
{
	public :
		Whale(const String&);
		inline ~Whale();
		String print_children_Details() const;
		
		const String& getSpecies() const;
		const unsigned char& getLifeExpectancy() const;
		const String& getContinent() const;
		const String& getFoodTypes() const;
		const unsigned char& getSpeed() const;
		const unsigned char& getPregnancyDuration() const;
		const unsigned char& getNumberYoungBorn() const;
		const unsigned char& getLowestDepth () const;
		
	private:
		static String species;
		static unsigned char  s_life_expectancy;
		static String s_continents;
		static String s_Food;
		static unsigned char s_speed;
		static unsigned char s_pregnancy_duration;
		static unsigned char s_young_born;
		static unsigned char s_lowet_depth;
};

inline Whale::Whale(const String& name):Animal(name){}
	
inline Whale::~Whale(){}

inline String Whale::print_children_Details() const
{
	std::stringstream ss;
	ss << "\npregnancy duration : " << static_cast<int>(getPregnancyDuration())
		<< "\nyoung born : " << static_cast<int>(getNumberYoungBorn())<< "\nLowest depth : " << static_cast<int>(getLowestDepth());
	String str_to_return=ss.str().c_str();
	return  str_to_return ;
}

inline const String& Whale::getSpecies() const
{
	return species;
}
inline const unsigned char& Whale::getLifeExpectancy() const
{
	return s_life_expectancy;
}
inline const String& Whale::getContinent() const
{
	return s_continents;
}
inline const String& Whale::getFoodTypes() const
{
	return s_Food;
}
inline const unsigned char& Whale::getSpeed() const
{
	return s_speed;
}

inline const unsigned char& Whale::getPregnancyDuration() const
{
	return s_pregnancy_duration;
}

inline const unsigned char& Whale::getLowestDepth () const
{
	return s_lowet_depth;
}

inline const unsigned char& Whale::getNumberYoungBorn()const
{
	return s_young_born;
}


#endif /* __WHALE_H__ */
