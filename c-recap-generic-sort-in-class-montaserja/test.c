#include"test.h"
#include"sort.h"
#include<stdio.h>
void test()
{
	
	my_compare compare=name_compare;
	
	Person persons[4]={{1,"ahmad",19},{5,"montaser",12},{2,"zahed",15},{2,"rotem",1}};
	printf("=============Persons array=============\n\n");
	print_array(persons,4);
	printf("\n\n");

	printf("=============Names sort=============\n\n");
	my_sort(persons,4,compare);
	print_array(persons,4);
	
	printf("=============id sort=============\n\n");
	printf("\n\n");
	compare=id_compare;
	my_sort(persons,4,compare);
	print_array(persons,4);

	printf("=============age sort=============\n\n");
	printf("\n\n");
	compare=age_compare;
	my_sort(persons,4,compare);
	print_array(persons,4);
}
