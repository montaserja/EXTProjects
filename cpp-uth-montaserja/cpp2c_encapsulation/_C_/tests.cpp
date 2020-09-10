#include"material.h"

vois testMatType()
{
	material_t mat;
	_Material_ctor(&mat,OTHER);
	printf("%s\n",getName_Material(&mat)=="OTHER" ? "get name Fuc passed" : "get name Fuc not passed");
}
