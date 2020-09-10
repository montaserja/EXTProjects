#ifndef __MATERIAL_H__
#define __MATERIAL_H__


#include "cpp2c_encapsulation_defs.h"


typedef enum Types
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
} Types;

typedef struct Material
{
	char type;
}Material;

void _Material_ctor(Material* const);

void _copy_material(Material* const,const Material* const);

static const char* getName_Material(Types type);

typedef struct Material_t
{
	Material father;
	Types material;
}Material_t;

void _Material_t_ctor(Material_t* const m, Types mat);
const char* name(const Material_t* const m) ;


typedef struct PhysicalBox
{
	Box box;
	Material_t material;
	
}PhysicalBox;

void copy_pBox(PhysicalBox* const pBox1,const PhysicalBox* const pBox2);
void _PhysicalBox_ctor_ddd(PhysicalBox* const,double l, double w, double h);
void _PhysicalBox_ctor_dddt(PhysicalBox* const,double l, double w, double h,Types t);
void _PhysicalBox_ctor_t(PhysicalBox* const,Types t);
void _PhysicalBox_dtor(PhysicalBox* const);

Types PBox_getMaterial(const PhysicalBox* const);
void printp(const PhysicalBox* const);

bool pBox_isEqual(const PhysicalBox* const, const PhysicalBox* const);
bool pBox_isNotEqual(const PhysicalBox* const, const PhysicalBox* const);
/*********************************************************************************************/


typedef struct WeightBox
{
	double m_weight;
	Box box;
}WeightBox;

void _WeightBox_ctor_dddd(WeightBox* const wBox,double l, double w, double h, double wgt);
void copy_WeightBox(WeightBox* const wBox,const WeightBox* const other);
void _WeightBox_dtor(WeightBox* const wBox);

void copy_wBox(WeightBox* const wBox,const WeightBox* const other);

double wBox_getWeight(const WeightBox* const);
void printw(const WeightBox* const);

bool wBox_isEqual(const WeightBox* const, const WeightBox* const);
bool wBox_isNotEqual(const WeightBox* const, const WeightBox* const);


















#endif /* __MATERIAL_H__ */
