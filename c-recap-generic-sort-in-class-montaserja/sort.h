#ifndef SORT_H
#define SORT_H
typedef struct Person
{
	int m_id;
	char name[16];
	unsigned char m_age;
}Person;


typedef int(*my_compare)(const Person*,const Person*);

void swap(Person *xp, Person *yp);
int name_compare(const Person* p1,const Person* p2);
int id_compare(const Person* p1,const Person* p2);
int age_compare(const Person* p1,const Person* p2);
void my_sort(Person arr[],int num,my_compare cmp_func);
void print_array(Person arr[],int num);
int strCmp(const char* s1, const char* s2);




#endif /*SORT_H*/

