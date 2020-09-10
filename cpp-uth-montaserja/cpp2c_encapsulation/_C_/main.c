
#include "material.h"
#include<stdio.h>
#include"tests.h"


void doMaterials()
{
    printf("\n--- Start doMaterials() ---\n\n");
    
    Material mat;
    printf("Size of Materials: %lu\n", sizeof(Material));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    struct MatTest { Material mat; Material_t mat_t; };
    
    printf("Size of Materials + Material_t: %lu\n", sizeof(struct MatTest ));


    Material_t mat1;
    _Material_t_ctor(&mat1,OTHER);
    
    Material_t mat2;
    _Material_t_ctor(&mat2,METAL);

    printf("\n--- End doMaterials() ---\n\n");
}

void doPhysicalBox()
{
    printf("\n--- Start doPhysicalBox() ---\n\n");

    PhysicalBox pb1;
    _PhysicalBox_ctor_dddt(&pb1,8, 6, 4, PLASTIC);
    
    PhysicalBox pb2;
    _PhysicalBox_ctor_t(&pb2, WOOD);
    
    PhysicalBox pb3;
    _PhysicalBox_ctor_ddd(&pb3,7, 7, 7);

    
    printf("\npb4 is copy-constructed from pb1\n");

    PhysicalBox pb4 ;
    copy_pBox(&pb4,&pb1);

   	printp(&pb4);
    printp(&pb1);

    printf("pb4 %s pb1\n", pBox_isEqual(&pb4,&pb1) ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    copy_pBox(&pb4,&pb3);
    printp(&pb4);
    printp(&pb3);
    printf("pb4 %s pb3\n", pBox_isEqual(&pb4,&pb3)  ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    _PhysicalBox_dtor(&pb4);
    _PhysicalBox_dtor(&pb3);
    _PhysicalBox_dtor(&pb2);
    _PhysicalBox_dtor(&pb1);

}

void doWeightBox()
{
    printf("\n--- Start doWeightBox() ---\n\n");

    WeightBox pw1;
     _WeightBox_ctor_dddd(&pw1,8, 6, 4, 25);
     
    WeightBox pw2; 
    _WeightBox_ctor_dddd(&pw2,1, 2, 3,0.0);
    
    WeightBox pw3;
     _WeightBox_ctor_dddd(&pw3,10, 20, 30, 15);
    
    printf("\npw4 is copy-constructed from pw1\n");
    WeightBox pw4 ;  
    copy_WeightBox(&pw4 , &pw1);
    printw(&pw4);
    printw(&pw1);
    printf("pw4 %s pw1\n", wBox_isEqual(&pw4,&pw1) ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    copy_wBox(&pw4,&pw3);

    printw(&pw4);
    printw(&pw3);
    printf("pw4 %s pw3\n",wBox_isEqual(&pw4,&pw3) ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");

    _WeightBox_dtor(&pw4);
    _WeightBox_dtor(&pw3);
    _WeightBox_dtor(&pw2);
    _WeightBox_dtor(&pw1);

}





int main()
{
    printf("\n--- Start main() ---\n\n");
testMatType();
    /*doMaterials();

    doPhysicalBox();

    doWeightBox();*/

    printf("\n--- End main() ---\n\n");

}
















