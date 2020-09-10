#include "test.h"
#include "vector.h"
#include <stdio.h>

void prr(void * ptr)
{
printf("%d\t",(int)*((int*)ptr));
}


void test(){

#ifdef _DEBUG


int ins=11;
	int hells[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

	int i=0;
	int j=90;
	void* res=&i;

	Vector *v = vectorCreate(2);
	for(;i<10;++i){
		vectorPush(v,&hells[i]);

	}

	printf("vector after creation:\n");
	vectorForEach(v,prr);
	printf("\n");
	printf("inserting 10 -> 3:\n");
	vectorInsert(v,&ins,10);
	vectorPrint(v,prr);
	printf("removing element from 3:\n");
	vectorRemove(v,3,&res);
	vectorPrint(v,prr);
	printf("removing element from 3:\n");
	vectorRemove(v,3,&res);
	vectorPrint(v,prr);
	vectorGetElement(v,3,&res);
	printf("element at 3 is %d \n",*((int*)res) );
	vectorSetElement(v,3,&j);
	printf("vector at the end:\n");
	vectorPrint(v,prr);


	vectorDestroy(&v);

/*int res=0;
	Vector* v=vectorCreate(1);
	vectorPrint(v);
	vectorPush(v, 1);
	vectorPush(v, 2);
	vectorPush(v, 3);
	vectorPush(v, 4);
	vectorPush(v, 4);
	vectorPush(v, 4);
	vectorPush(v, 70);
	vectorPrint(v);
	
	vectorPop(v,&res);
	printf("%d\n",res);
	printf("%d\n",vectorGetElement(v,2,&res));
	printf("%d\n",res);
	vectorSetElement(v,2,16);
	printf("%d\n",vectorGetElement(v,2,&res));
	printf("%d\n",res);

	vectorPrint(v);

	vectorInsert(v,50,5);
	vectorPrint(v);

	vectorRemove(v,0,&res);
	printf("%d\n",res);
	vectorPrint(v);
	
	printf("%lu\n",vectorCount(v,50));
	vectorDestroy(&v);*/

#endif /* _DEBUG */



}

