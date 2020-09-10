#ifndef __SHARK_H__
#define __SHARK_H__

#include"String.h"
#include"fish.h"
#include <sstream>

class Shark : public Fish
{
	public:
		Shark(const String& name);
		~Shark();
		
		const String& getSpecies() const;
		const unsigned char& getLifeExpectancy() const;
		const String& getContinent() const;
		const String& getFoodTypes() const;
		const unsigned char& getSpeed() const;
		const unsigned char& getLowestDepth () const;
		
	private:
		static String species;
		static unsigned char  s_life_expectancy;
		static String s_continents;
		static String s_Food;
		static unsigned char s_speed;
		static unsigned char s_lowet_depth;

};

inline Shark::Shark(const String& name):Fish(name){}

inline Shark::~Shark(){}




inline const String& Shark::getSpecies() const
{
	return species;
}
inline const unsigned char& Shark::getLifeExpectancy() const
{
	return s_life_expectancy;
}
inline const String& Shark::getContinent() const
{
	return s_continents;
}
inline const String& Shark::getFoodTypes() const
{
	return s_Food;
}
inline const unsigned char& Shark::getSpeed() const
{
	return s_speed;
}

inline const unsigned char& Shark::getLowestDepth () const
{
	return s_lowet_depth;
}

#endif /* __SHARK_H__ */


#ifndef __CLOWNFISH_H__
#define __CLOWNFISH_H__

#include"String.h"
#include"fish.h"
#include <sstream>

class ClownFish : public Fish
{
	public:
		ClownFish(const String& name);
		~ClownFish();
		
		const String& getSpecies() const;
		const unsigned char& getLifeExpectancy() const;
		const String& getContinent() const;
		const String& getFoodTypes() const;
		const unsigned char& getSpeed() const;
		const unsigned char& getLowestDepth () const;
		
	private:
		static String species;
		static unsigned char  s_life_expectancy;
		static String s_continents;
		static String s_Food;
		static unsigned char s_speed;
		static unsigned char s_lowet_depth;

};

inline ClownFish::ClownFish(const String& name):Fish(name){}

inline ClownFish::~ClownFish(){}




inline const String& ClownFish::getSpecies() const
{
	return species;
}
inline const unsigned char& ClownFish::getLifeExpectancy() const
{
	return s_life_expectancy;
}
inline const String& ClownFish::getContinent() const
{
	return s_continents;
}
inline const String& ClownFish::getFoodTypes() const
{
	return s_Food;
}
inline const unsigned char& ClownFish::getSpeed() const
{
	return s_speed;
}

inline const unsigned char& ClownFish::getLowestDepth () const
{
	return s_lowet_depth;
}

#endif /* __CLOWNFISH_H__ */



















