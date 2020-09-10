#include"material.h"
#include<stdio.h>


static const char* getName_Material(Types type)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    return names[type];
}


void _Material_ctor(Material* const material){}

void _copy_material(Material* const m1,const Material* const m2){}

void _Material_t_ctor(Material_t* const m, Types mat)
{ 
	m->material=mat;
	printf("Material created, set to %s\n", name(m)); 
}
const char* name(const Material_t* const m)
{ 
return getName_Material(m->material) ;
}

void _PhysicalBox_ctor_ddd(PhysicalBox* const pBox,double l, double w, double h)
{
	pBox->box=_Box_ddd(l,w,h);
	_Material_t_ctor(&(pBox->material),OTHER);
	printp(pBox);
	
}
void _PhysicalBox_ctor_dddt(PhysicalBox* const pBox,double l, double w, double h,Types t)
{
	pBox->box=_Box_ddd(l,w,h);
	_Material_t_ctor(&(pBox->material),t);
	printp(pBox);
}


void _PhysicalBox_ctor_t(PhysicalBox* const pBox,Types t)
{
	pBox->box=_Box_d(1);
	_Material_t_ctor(&(pBox->material),t);
	printp(pBox);
}

void copy_pBox(PhysicalBox* const pBox1,const PhysicalBox* const pBox2)
{
	pBox1->box=pBox2->box;
	pBox1->material=pBox2->material;
}


void _PhysicalBox_dtor(PhysicalBox* const pBox)
{

printf("PhysicalBox dtor, %f x %f x %f, %s; ", getLength(&(pBox->box)), getWidth(&(pBox->box)), getHeight(&(pBox->box)),
 name(&pBox->material));
  dtor_box(&pBox->box);
}

Types PBox_getMaterial(const PhysicalBox* const pBox)
{
	return pBox->material.material;
}

void printp(const PhysicalBox* const pBox)
{
	printf("PhysicalBox, made of %s; ", name(&pBox->material));
    print_Box(&pBox->box);
}

bool pBox_isEqual(const PhysicalBox* const pBox1, const PhysicalBox* const pBox2)
{
	return box_isEqual(&pBox1->box,&pBox2->box) && PBox_getMaterial(pBox1) == PBox_getMaterial(pBox2);
}



bool pBox_isNotEqual(const PhysicalBox* const pBox1, const PhysicalBox* const pBox2)
{
	return !pBox_isEqual(pBox1,pBox2);
}


/*********************************************************************************************/



void _WeightBox_ctor_dddd(WeightBox* const wBox,double l, double w, double h, double wgt)
{
	wBox->box=_Box_ddd(l,w,h);
	wBox->m_weight=wgt;
	printw(wBox);
}

void copy_WeightBox(WeightBox* const wBox,const WeightBox* const other)
{
	wBox->box=other->box;
	wBox->m_weight=other->m_weight;
	printw(wBox);
}
void _WeightBox_dtor(WeightBox* const wBox)
{
	dtor_box(&wBox->box);
	printf("Destructing WeightBox; ");
    printw(wBox);
}

void copy_wBox(WeightBox* const wBox,const WeightBox* const other)
{
	copy_WeightBox(wBox,other);
}

double wBox_getWeight(const WeightBox* const wBox)
{
	return wBox->m_weight;
}

void printw(const WeightBox* const wBox)
{
	printf("WeightBox, weight: %f; ", wBox->m_weight);
    print_Box(&wBox->box);
}


bool wBox_isEqual(const WeightBox* const wBox1, const WeightBox* const wBox2)
{
	return box_isEqual(&wBox1->box,&wBox2->box) && wBox1->m_weight == wBox2->m_weight; 
}
bool wBox_isNotEqual(const WeightBox* const wBox1, const WeightBox* const wBox2)
{
	return !wBox_isEqual(wBox1,wBox2);
}





























