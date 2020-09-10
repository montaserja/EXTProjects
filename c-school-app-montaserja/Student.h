#ifndef __STUDENT_H__
#define __STUDENT_H__
#include"String.h"
#include"Person.h"

using std::cout;
using std::endl;
class Student: public Person
{
public:
	inline Student(const String&,unsigned char );
	inline void action();
private:
	String name;
	unsigned char grade;
	

};

inline Student::Student(const String& name,unsigned char grade):Person(name),grade(grade){}

inline void Student::action()
{
	cout << "HI, I'm " << getName() <<" ,my ID is: "<< getId() <<" ,and My grade is " << static_cast<int>(grade) << " ,so i don't know" << endl;
}

#endif //__STUDENT_H__
