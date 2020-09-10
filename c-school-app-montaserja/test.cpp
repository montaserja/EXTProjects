#include"test.h"
#include <iostream>

#include <string>
#include <vector>
#include <list>
#include <map>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "School.h"
using std::cout;
using std::endl;

using namespace std;

void test1()
{
	/*Student s("Montaser",82);
	Student s2("Maar",40);


	s.action();
	s2.action();

	Teacher t("Amitai","Cpp");
	t.action();*/

	Student s1("A" , 54);
	Student s2("B" , 65);
	Student s3("C" , 77);
	Student s4("D" , 89);
	Student s5("E" , 54);
	Student s6("F" , 65);
	Student s7("G" , 77);
	Student s8("H" , 89);


	


	School c;
	cout << "----------------------there is no students-----------------------" <<endl;
	c.pairTeacherToStudent(2);
	c.addStudent(&s1);
	c.addStudent(&s2);
	c.addStudent(&s3);
	c.addStudent(&s4);
	c.addStudent(&s5);
	c.addStudent(&s6);
	c.pairTeacherToStudent(2);
	
	Teacher t1("Amitai","Cpp");
	Teacher t2("fdfd","asdasx");
	Teacher t3("acd","asdasd");
	c.addTeacher(&t1);
	c.addTeacher(&t2);
	c.addTeacher(&t3);
cout << "----------------------there is no teachers-----------------------" <<endl;
	c.pairTeacherToStudent(2);

	
cout << "----------------------pair teacher 2 students-----------------------" <<endl;
	c.printMap();
	cout << "----------------------remove student id=6-----------------------" <<endl;
	c.remove_student(6);
	cout << "----------------------remove student id=5-----------------------" <<endl;
	c.remove_student(5);
	cout << "----------------------remove teacher id=10-----------------------" <<endl;
	c.remove_teacher(9);

	cout << "----------------------pair teacher 10 students-----------------------" <<endl;
	c.pairTeacherToStudent(10);
	c.printMap();

	
				
    		
	


}
