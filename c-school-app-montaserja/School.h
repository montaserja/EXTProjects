#ifndef __SCHOOL_H__
#define __SCHOOL_H__
#include <map>
#include <vector>
#include <list>

#include"Student.h"
#include"Teacher.h"
#include"String.h"

typedef std::vector<Student*> StudentVector;
typedef std::vector<Teacher*> TeacherVector;
typedef std::map< size_t, std::list<Student*> > MapVector;
typedef std::list<Student*> List;
typedef std::vector<Student*>::iterator StudentIterator;
typedef std::vector<Teacher*>::iterator TeacherIterator;


class School
{
public:
	void addStudent(Student* student);
	void addTeacher(Teacher* teacher);
	size_t getNumOfStudents() const;
	size_t getNumOfTeachers() const;
	void pairTeacherToStudent(size_t ratio);
	List getTeacherStudents(const size_t &teacherId) const;
	void printMap();
	const MapVector getMap();
	Student* remove_student(size_t id_to_remove);
	void remove_student_from_map( Student* student);
	Teacher* remove_teacher(size_t id_to_remove);
	Teacher* find_teacher_byId(size_t id_to_remove);
	
	

	//remove student
	//remove teacher

private:
	StudentVector students;//typedef std::vector<Student*>
	TeacherVector teachers;
	MapVector  linking_map;
	

	
};

inline void School::addStudent(Student* student)
{
	students.push_back(student);
}

inline void School::addTeacher(Teacher* teacher)
{
	teachers.push_back(teacher);
}

inline //inline
size_t School::getNumOfStudents() const
{
	return students.size();
}

inline size_t School::getNumOfTeachers() const
{
	return teachers.size();
}


inline const MapVector School::getMap()
{
return linking_map;
}


inline List School::getTeacherStudents(const size_t &teacherId) const 
{
	return linking_map.find(teacherId)->second;
}



#endif //__SCHOOL_H__
