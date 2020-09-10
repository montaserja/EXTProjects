#include"School.h"



void School::pairTeacherToStudent(size_t ratio)//refactor //not name --> id
{
	if(!students.size() || !teachers.size())
	{
		std::cout << "no students or teachers" <<std::endl;
		return;
	}

	StudentIterator s_iter = students.begin();
	TeacherIterator t_iter = teachers.begin();
	
	size_t i=0;
	List list;

	while(s_iter != students.end() && t_iter != teachers.end())
	{
		
		if(i<ratio)
		{
			list.push_back(*s_iter);
			++s_iter;
			++i;		
		}
		else
		{
			
			linking_map[(*t_iter)->getId()] =  list;	
			list.clear();
			++t_iter;
			i=0;	
		}
		
	}
	if(list.size()!=0)
	{
		linking_map[(*t_iter)->getId()] =  list;	
		list.clear();
		++t_iter;
		i=0;
	}
}


void School::printMap()
{
	 for (MapVector::iterator it=linking_map.begin(); it!=linking_map.end(); ++it){
			std::cout << "teacher ID : " << it->first << '\n';
			List students=(it->second);
			List::iterator v_it=students.begin();

			for(;v_it!=students.end();++v_it){
				std::cout << "Student name : " << (*v_it)->getName() << '\n';
			}
			
		cout<< endl;
	}

}

Teacher* School::find_teacher_byId(size_t id_to_remove)
{
	TeacherIterator it =teachers.begin();
	int i=0;
	while(it !=teachers.end())
	{
		if((*it)->getId() == id_to_remove)
		{
			teachers.erase(teachers.begin()+i);
			return *it;	
		}
		++i;
	}
	return NULL;
}

Teacher* School::remove_teacher(size_t id_to_remove)
{
	
	Teacher* teacher_to_remove=find_teacher_byId(id_to_remove);
	
	if(!teacher_to_remove)
	{
		std::cout << "Teacher Not Found" << std::endl;
		return NULL;
	}
	MapVector::iterator it;
	
	it=linking_map.find(id_to_remove);
  	linking_map.erase (it);
  	//teachers.erase(teacher_to_remove);
  	
  	return teacher_to_remove;
	
	
}

Student* School::remove_student(size_t id_to_remove)
{
	StudentIterator it = students.begin();
	int i=0;
	while(it !=students.end())
	{
		if((*it)->getId() == id_to_remove)
		{
			students.erase(students.begin()+i);
			remove_student_from_map(*it);
			return *it;
		}
		++it;
		++i;
	}

		std::cout << "Student Not Found" << std::endl;
		return NULL;
	
}

void School::remove_student_from_map(  Student* student)
{
	for (MapVector::iterator it=linking_map.begin(); it!=linking_map.end(); ++it)
	{
		(it->second).remove(student);
	}
}






