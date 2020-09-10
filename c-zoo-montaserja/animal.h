#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include"String.h"

enum Continents{AFRICA,ASIA,ANTARCTICA,EUROPE,NORTH_AMERICA,AUSTRALIA,SOUTH_AMERICA};

enum FoodType{CARNIVORES,HERBIVORES,OMNIVORES,MEAT};

static const char * const types[] ={"CARNIVORES","HERBIVORES","OMNIVORES"};

class Animal
{
	public:
		Animal(const String&);
		const String& getName() const;
		
		virtual const String& getSpecies() const=0;
		virtual const unsigned char& getLifeExpectancy() const=0;
		virtual const String& getContinent() const=0;
		virtual const String& getFoodTypes() const=0;
		virtual const unsigned char& getSpeed() const=0;
		
		virtual ~Animal();
		String printDetails() const;
		virtual String print_children_Details() const =0;
		friend std::ostream& operator<<(std::ostream& out,const Animal& animal);
	
	private:
		const String m_name;
};

inline Animal::Animal(const String& name):m_name(name){}

inline const String& Animal::getName() const
{
	return m_name;
}

inline Animal::~Animal(){}






#endif /* __ANIMAL_H__ */
