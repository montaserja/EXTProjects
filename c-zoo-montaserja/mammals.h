#ifndef __LION_H__
#define __LION_H__

#include"String.h"
#include"mammal.h"
#include <sstream>

class Lion : public Mammal
{
	public:
		Lion(const String& name);
		~Lion();
		
		const String& getSpecies() const;
		const unsigned char& getLifeExpectancy() const;
		const String& getContinent() const;
		const String& getFoodTypes() const;
		const unsigned char& getSpeed() const;
		const unsigned char& getPregnancyDuration() const;
		const unsigned char& getNumberYoungBorn()const;
		
	private:
		static String species;
		static unsigned char  s_life_expectancy;
		static String s_continents;
		static String s_Food;
		static unsigned char s_speed;
		static unsigned char s_pregnancy_duration;
		static unsigned char s_young_born;

};

inline Lion::Lion(const String& name):Mammal(name){}

inline Lion::~Lion(){}




inline const String& Lion::getSpecies() const
{
	return species;
}
inline const unsigned char& Lion::getLifeExpectancy() const
{
	return s_life_expectancy;
}
inline const String& Lion::getContinent() const
{
	return s_continents;
}
inline const String& Lion::getFoodTypes() const
{
	return s_Food;
}
inline const unsigned char& Lion::getSpeed() const
{
	return s_speed;
}

inline const unsigned char& Lion::getPregnancyDuration() const
{
	return s_pregnancy_duration;
}
inline const unsigned char& Lion::getNumberYoungBorn()const
{
	return s_young_born;
}

#endif /* __LION_H__ */








#ifndef __MONKEY_H__
#define __MONKEY_H__

#include"String.h"
#include"mammal.h"
#include <sstream>

class Monkey : public Mammal
{
	public:
		Monkey(const String& name);
		~Monkey();
		
		const String& getSpecies() const;
		const unsigned char& getLifeExpectancy() const;
		const String& getContinent() const;
		const String& getFoodTypes() const;
		const unsigned char& getSpeed() const;
		const unsigned char& getPregnancyDuration() const;
		const unsigned char& getNumberYoungBorn()const;
		
	private:
		static String species;
		static unsigned char  s_life_expectancy;
		static String s_continents;
		static String s_Food;
		static unsigned char s_speed;
		static unsigned char s_pregnancy_duration;
		static unsigned char s_young_born;

};

inline Monkey::Monkey(const String& name):Mammal(name){}

inline Monkey::~Monkey(){}




inline const String& Monkey::getSpecies() const
{
	return species;
}
inline const unsigned char& Monkey::getLifeExpectancy() const
{
	return s_life_expectancy;
}
inline const String& Monkey::getContinent() const
{
	return s_continents;
}
inline const String& Monkey::getFoodTypes() const
{
	return s_Food;
}
inline const unsigned char& Monkey::getSpeed() const
{
	return s_speed;
}

inline const unsigned char& Monkey::getPregnancyDuration() const
{
	return s_pregnancy_duration;
}
inline const unsigned char& Monkey::getNumberYoungBorn()const
{
	return s_young_born;
}

#endif /* __MONKEY_H__ */



#ifndef __DOG_H__
#define __DOG_H__

#include"String.h"
#include"mammal.h"
#include <sstream>

class Dog : public Mammal
{
	public:
		Dog(const String& name);
		~Dog();
		
		const String& getSpecies() const;
		const unsigned char& getLifeExpectancy() const;
		const String& getContinent() const;
		const String& getFoodTypes() const;
		const unsigned char& getSpeed() const;
		const unsigned char& getPregnancyDuration() const;
		const unsigned char& getNumberYoungBorn()const;
		
	private:
		static String species;
		static unsigned char  s_life_expectancy;
		static String s_continents;
		static String s_Food;
		static unsigned char s_speed;
		static unsigned char s_pregnancy_duration;
		static unsigned char s_young_born;

};

inline Dog::Dog(const String& name):Mammal(name){}

inline Dog::~Dog(){}




inline const String& Dog::getSpecies() const
{
	return species;
}
inline const unsigned char& Dog::getLifeExpectancy() const
{
	return s_life_expectancy;
}
inline const String& Dog::getContinent() const
{
	return s_continents;
}
inline const String& Dog::getFoodTypes() const
{
	return s_Food;
}
inline const unsigned char& Dog::getSpeed() const
{
	return s_speed;
}

inline const unsigned char& Dog::getPregnancyDuration() const
{
	return s_pregnancy_duration;
}
inline const unsigned char& Dog::getNumberYoungBorn()const
{
	return s_young_born;
}

#endif /* __DOG_H__ */










