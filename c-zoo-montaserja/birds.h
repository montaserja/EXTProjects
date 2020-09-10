#ifndef __GOOSE_H__
#define __GOOSE_H__

#include"String.h"
#include"bird.h"
#include <sstream>

class Goose : public Bird
{
	public:
		Goose(const String& name);
		~Goose();
		
		const String& getSpecies() const;
		const unsigned char& getLifeExpectancy() const;
		const String& getContinent() const;
		const String& getFoodTypes() const;
		const unsigned char& getSpeed() const;
		const unsigned short int& getHeight() const;
		const float& getWingSpan() const;
		
	private:
		static String species;
		static unsigned char  s_life_expectancy;
		static String s_continents;
		static String s_Food;
		static unsigned char s_speed;
		static unsigned short int s_Heigth;
		static float s_span;
};

inline Goose::Goose(const String& name):Bird(name){}

inline Goose::~Goose(){}


inline const String& Goose::getSpecies() const
{
	return species;
}
inline const unsigned char& Goose::getLifeExpectancy() const
{
	return s_life_expectancy;
}
inline const String& Goose::getContinent() const
{
	return s_continents;
}
inline const String& Goose::getFoodTypes() const
{
	return s_Food;
}
inline const unsigned char& Goose::getSpeed() const
{
	return s_speed;
}

inline const unsigned short int& Goose::getHeight() const
{
	return s_Heigth;
}
inline const float& Goose::getWingSpan() const
{
	return s_span;
}

#endif /* __GOOSE_H__ */




#ifndef __SNOWYOWL_H__
#define __SNOWYOWL_H__

#include"String.h"
#include"bird.h"
#include <sstream>

class Snowyowl : public Bird
{
	public:
		Snowyowl(const String& name);
		~Snowyowl();
		
		const String& getSpecies() const;
		const unsigned char& getLifeExpectancy() const;
		const String& getContinent() const;
		const String& getFoodTypes() const;
		const unsigned char& getSpeed() const;
		const unsigned short int& getHeight() const;
		const float& getWingSpan() const;
		
	private:
		static String species;
		static unsigned char  s_life_expectancy;
		static String s_continents;
		static String s_Food;
		static unsigned char s_speed;
		static unsigned short int s_Heigth;
		static float s_span;
};

inline Snowyowl::Snowyowl(const String& name):Bird(name){}

inline Snowyowl::~Snowyowl(){}


inline const String& Snowyowl::getSpecies() const
{
	return species;
}
inline const unsigned char& Snowyowl::getLifeExpectancy() const
{
	return s_life_expectancy;
}
inline const String& Snowyowl::getContinent() const
{
	return s_continents;
}
inline const String& Snowyowl::getFoodTypes() const
{
	return s_Food;
}
inline const unsigned char& Snowyowl::getSpeed() const
{
	return s_speed;
}

inline const unsigned short int& Snowyowl::getHeight() const
{
	return s_Heigth;
}
inline const float& Snowyowl::getWingSpan() const
{
	return s_span;
}

#endif /* __SNOWYOWL_H__ */
