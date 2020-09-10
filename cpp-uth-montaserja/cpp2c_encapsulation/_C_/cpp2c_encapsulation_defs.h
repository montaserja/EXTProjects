#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__

#define NUM_BOXES 3
#define DEF_MSG ("The total volume held on the shelf is")


/***********************************Box***************************************/
typedef struct Box Box;

struct Box
{
    double width;
    double height;
    double length;
};
typedef enum bool{false,true}bool;

Box _Box_d(double dim);
Box _Box_ddd(double l, double w, double h);
double getWidth(const Box* const);
double getLength(const Box* const);
double getHeight(const Box* const);
double getVolume(const Box* const);

void print_Box(const Box * const) ;

Box copy_assignment(const Box* const  box);

void mult_this_by_d(Box* box,double mult);

void dtor_box(Box*);

Box mult_box_d(const Box* box, double mult);
Box mult_d_box(double mult, const Box* box);
bool box_isEqual(const Box* const lhs, const Box* const rhs);
bool box_notEqual(const Box* const lhs, const Box* const rhs);


/**************************************************************************/

/*******************************Shelf*******************************************/

static const char* message=DEF_MSG;
typedef struct Shelf Shelf;

struct Shelf
{
    Box* boxes;
};

Shelf _Shelf();
void setBox(Shelf* ,int index, const Box* const dims);

double shelf_getVolume(const Shelf* const) ;

Box getBox(Shelf* shelf,int index);
void print_Shelf(const Shelf* const);
int getNumBoxes();
 void setMessage(const char* msg);
 void dtor_Shelf(Shelf*);

/**************************************************************************/

#endif /* __CPP2C_ENCAPSULATION_DEFS_H__ */



