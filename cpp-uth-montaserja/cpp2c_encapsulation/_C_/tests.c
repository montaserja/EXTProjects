
#include"tests.h"

void testMatType()
{
	Material_t mat;
	_Material_t_ctor(&mat,OTHER);
	const char* o=name(&mat);
	
	printf("%d\n",o=="Other");
}	
