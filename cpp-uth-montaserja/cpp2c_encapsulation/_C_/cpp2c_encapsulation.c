#include"cpp2c_encapsulation_defs.h"
#include<stdio.h>

static Box largeBox;
bool n=false;

void thisFunc()
{
    printf("\n--- thisFunc() ---\n\n"); 
    static Box box99;
    if(n==false){
    	box99=_Box_ddd(99,99,99);
    	n=true;
    	
    }
    mult_this_by_d(&box99,10);
}

void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");

    Box b1=_Box_d(3);
    Box b2=_Box_ddd(4,5,6);
	
	printf("b1 volume: %f\n",getVolume(&b1));
	printf("b2 volume: %f\n",getVolume(&b2));
	
	mult_this_by_d(&b1,1.5);
	mult_this_by_d(&b2,0.5);
	
	printf("b1 volume: %f\n",getVolume(&b1));
	printf("b2 volume: %f\n",getVolume(&b2));
	
	Box b3 = copy_assignment(&b2);
    Box b4 = mult_d_box(3, &b2);
    

	
	printf("b3 %s b4\n",  box_isEqual(&b3,&b4)  ? "equals" : "does not equal");
	
	mult_this_by_d(&b3,1.5);
	mult_this_by_d(&b4,0.5);
    
    printf("Now, b3 %s b4\n",  box_isEqual(&b3,&b4)  ? "equals" : "does not equal");
	dtor_box(&b1);
	dtor_box(&b2);
	dtor_box(&b3);
	dtor_box(&b4);

  printf("\n--- End doBoxes() ---\n\n");
}


void doShelves()
{
	printf("\n--- start doShelves() ---\n\n");
	Box aBox=_Box_d(5);
	Shelf aShelf=_Shelf();
	print_Shelf(&aShelf);
	setBox(&aShelf,1, &largeBox);
	setBox(&aShelf,0, &aBox);
	
	print_Shelf(&aShelf);
	setMessage("This is the total volume on the shelf:");
	print_Shelf(&aShelf);
	setMessage("Shelf's volume:");
	print_Shelf(&aShelf);
	dtor_Shelf(&aShelf);
	printf("\n--- end doShelves() ---\n\n");
	dtor_box(&aBox);

}
/*
int main()
{
	largeBox=_Box_ddd(10, 20, 30);
  	printf("\n--- Start main() ---\n\n");
	doBoxes();
	thisFunc();
	thisFunc();
	thisFunc();
	doShelves();
	
	dtor_box(&largeBox);
	return 0;
}*/
