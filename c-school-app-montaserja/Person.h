#ifndef __PERSON_H__
#define __PERSON_H__

#include"String.h"

class Person
{
public:
	inline Person(const String&);
	inline const String&  getName();
	inline size_t getId();
	inline virtual void action()=0;
	inline virtual ~Person();

private:
	String name;
	static size_t id;
	const size_t m_id;
	

};

inline Person::Person(const String& name):name(name),m_id(++id){}

inline const String&  Person::getName()
{
	return name;
	
}

inline size_t Person::getId()
{
	return m_id;
}

inline Person::~Person(){}



#endif //__PERSON_H__
