#ifndef __TEACHER_H__
#define __TEACHER_H__

#include"Person.h"
#include"String.h"

using std::cout;
using std::endl;

class Teacher : public Person
{

public:
	inline Teacher(const String&, const String&);
	inline void action();

private:
	String name;
	String lesson;
	
};

inline Teacher::Teacher(const String& name, const String& lesson):Person(name),lesson(lesson){}

inline void Teacher::action()
{
	cout << "HI, I'm " << getName() <<" ,my ID is: "<< getId() <<" ,I'm teaching " << lesson << " ,so i don't know" << endl;
}

#endif //__TEACHER_H__
