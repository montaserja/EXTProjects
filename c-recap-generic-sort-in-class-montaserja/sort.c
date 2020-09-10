#include<stdio.h>
#include<string.h>
#include"sort.h"




void swap(Person *xp, Person *yp) 
{ 
    Person temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}


int strCmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}



int name_compare(const Person* p1,const Person* p2)
{
	return strCmp(p1->name,p2->name);
}

int id_compare(const Person* p1,const Person* p2)
{
	return p1->m_id-p2->m_id;
}

int age_compare(const Person* p1,const Person* p2)
{
	return p1->m_age-p2->m_age;
}



void my_sort(Person arr[],int num,my_compare cmp_func)
{
	int i, j; 
	for (i = 0; i < num-1; i++)   
		for (j = 0; j < num-i-1; j++)  
			if(cmp_func(&arr[j],&arr[j+1])>0) 
		              swap(&arr[j], &arr[j+1]);
}






void print_array(Person arr[],int num)
{
	int i=0;
	for (i = 0; i < num; i++)
	{
		printf("ID: %d Name: %s Age: %d\n",arr[i].m_id,arr[i].name,arr[i].m_age);
	}
}


















