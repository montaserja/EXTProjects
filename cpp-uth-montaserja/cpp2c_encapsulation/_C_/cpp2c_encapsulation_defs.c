#include"cpp2c_encapsulation_defs.h"

#include<stdlib.h>
#include<stdio.h>




Box _Box_d(double dim)
{
	Box box;
	box.width=dim;
	box.height=dim;
	box.length=dim;
	print_Box(&box);
return box;
}

Box _Box_ddd(double l, double w, double h)
{
	Box box;
	box.width=w;
	box.height=h;
	box.length=l;
	print_Box(&box);
return box;
}


double getWidth(const Box* const box) 
{
	return box->width;
}


double getLength(const Box* const box)
{
	return box->length;
}

double getHeight(const Box* const box)
{
	return box->height;
}

double getVolume(const Box* const box)
{
	return box->height * box->width * box->length;
}


void print_Box(const Box * const box)
{
	printf("Box: %f x %f x %f\n", box->width, box->height, box->length);
}


Box copy_assignment(const Box* const box)
{
	Box copy;
	copy.width=box->width;
	copy.height=box->height;
	copy.length=box->length;
	
return copy;
}

void dtor_box(Box* box)
{
	printf("Box destructor, %f x %f x %f\n", box->width, box->height, box->length);
}


void mult_this_by_d(Box* box,double mult)
{
	box->width*=mult;
	box->height*=mult;
	box->length*=mult;
}


Box mult_box_d(const Box* box, double mult)
{
	Box box2;
	box2.width=box->width*mult;
	box2.height=box->height*mult;
	box2.length=box->height*mult;
	return box2;
}

Box mult_d_box(double mult, const Box* box)
{
	return mult_box_d(box,mult);
}


bool box_isEqual(const Box* const lhs, const Box* const rhs)
{
return getWidth(lhs) == getWidth(rhs) && getHeight(lhs) == getHeight(rhs) && getLength(lhs) == getLength(rhs);
}


bool box_notEqual(const Box* const lhs, const Box* const rhs)
{
	return !(box_isEqual(lhs,rhs));
}


Shelf _Shelf()
{
	Shelf shelf;
	shelf.boxes=malloc(sizeof(Box)*NUM_BOXES);
	shelf.boxes[0]=_Box_d(1);
	shelf.boxes[1]=_Box_d(1);
	shelf.boxes[2]=_Box_d(1);
	return shelf;
}

void setBox(Shelf* shelf,int index, const Box* const dims)
{
	shelf->boxes[index]=*dims;

}

double shelf_getVolume(const Shelf* const shelf) 
{
	double vol = 0;
    for (int i = 0; i < NUM_BOXES; ++i)
        vol += getVolume(&shelf->boxes[i]);

    return vol;
}

Box getBox(Shelf* shelf,int index)
{
	return shelf->boxes[index];
}

void print_Shelf(const Shelf* const shelf)
{
	printf("%s %f\n", message, shelf_getVolume(shelf));
}

void dtor_Shelf(Shelf* shelf)
{
 for (int i = 0; i < NUM_BOXES; ++i)
 		dtor_box(&shelf->boxes[i]);
	
	free(shelf->boxes);
}

int getNumBoxes()
{
	return NUM_BOXES;
}

void setMessage(const char* msg)
{
	message=msg;
}
















