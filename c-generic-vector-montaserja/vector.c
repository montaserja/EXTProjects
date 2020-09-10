#include"vector.h"
#include<stdio.h>
#include<stdlib.h>
struct Vector
{
	void**	m_arr;
	size_t 	m_length;
	size_t 	m_numOfItems;
};

Vector* vectorCreate(size_t length)
{
	Vector *vector = malloc(sizeof(Vector));
	if(!vector)
	{
		return NULL;
	}
	vector->m_arr = malloc(length * sizeof(void*));
	if(!vector->m_arr)
	{
		return NULL;
	}
	vector->m_length = length;
	vector->m_numOfItems = 0;

	return vector;
}

ErrorCode vectorPush(Vector *vector, void* value)
{
	if (!vector)
	{
		return E_NULL_PTR;
	}

	/* Validate overflow. If full, reallocate. */
	if ((vector->m_numOfItems) >= (vector->m_length))
	{
		/* Don't need to free existing memory: https://stackoverflow.com/questions/46461236/does-realloc-free-the-existing-memory */
		void **res = realloc(vector->m_arr, sizeof(void*)*(vector->m_length*2));
		if (!res)
		{
			return E_ALLOCATION_ERROR;
		}

		vector->m_arr = res;
		vector->m_length *= 2;
	}

	vector->m_arr[vector->m_numOfItems++]=value;

	
return E_OK;
}

size_t vectorForEach(Vector *vector,Func func)
{
	int i=0;
	/*size_t count=0;*/
	if(vector==NULL)
	{
		return 0;
	}
	while(i<vector->m_numOfItems)
	{
		func(vector->m_arr[i++]);
		
	}
	return 0;
}
 void vectorPrint(Vector *vector,Print print)
{	
	int i=0;
	
	if(vector==NULL)
	{
		return;
	}
	while(i<vector->m_numOfItems)
	{
		print(vector->m_arr[i++]);
		/*printf("%d\t",(int)*((int*)vector->m_arr[i++]));*/
	}
	printf("\n");

}

ErrorCode vectorPop(Vector *vector, void **res)
{
	
	if(vector==NULL || res==NULL)
	{
		return E_NULL_PTR;
	}
	if(vector->m_numOfItems==0)
	{
		return E_UNDERFLOW;
	}
	*res=vector->m_arr[vector->m_numOfItems-1];
	vector->m_numOfItems--;
	return E_OK;
}


ErrorCode vectorGetElement(const Vector *vector, size_t index, void **res)
{
	if(vector==NULL || res==NULL)
	{
		return E_NULL_PTR;
	}
	if(index >= vector->m_numOfItems)
	{
		return E_BAD_INDEX;
	}
	*res =vector->m_arr[index];
	return E_OK;
}

ErrorCode vectorSetElement(Vector *vector, size_t index, void *value)
{
	if(index >= vector->m_numOfItems)
	{
		return E_BAD_INDEX;
	}
	vector->m_arr[index]=value;
	return E_OK;
}

size_t vectorGetSize(const Vector *vector)
{
	return vector->m_numOfItems;
}

size_t vectorGetCapacity(const Vector *vector)
{
	return vector->m_length;
}

ErrorCode vectorInsert(Vector *vector, void* value, size_t index)
{
	
	size_t i;

	if(index > vector->m_numOfItems)
	{
		return E_BAD_INDEX;
	}

	if((vector->m_numOfItems) >= (vector->m_length))
	{
		void **tmp =realloc(vector->m_arr, sizeof(void*)*(vector->m_length*2));
		if(tmp==NULL)
		{
			return E_ALLOCATION_ERROR;
		}
		vector->m_arr = tmp;
		vector->m_length*=2;
	}
	
	if(index == vector->m_numOfItems)
	{

	return vectorPush(vector,value);
	
	}


	i=vector->m_numOfItems++;


	while(i>index)
	{
		
		vector->m_arr[i]=vector->m_arr[i-1];
		--i;
	}
	
	vector->m_arr[i+1]=value;

	return E_OK;
}


ErrorCode vectorRemove(Vector *vector, size_t index, void **res)
{
	if(vector==NULL || res==NULL)
	{
		return E_NULL_PTR;
	}
	if(index >= vector->m_numOfItems)
	{
		return E_BAD_INDEX;
	}
	*res=vector->m_arr[index];
	while(index < vector->m_numOfItems-1)
	{
		vector->m_arr[index]=vector->m_arr[index+1];
		++index;
	}
	vector->m_arr[index]=0;
	vector->m_numOfItems--;
	return E_OK;
}

/*size_t vectorCount(const Vector *vector, void *value)
{
	
	size_t count=0,i=0;
	if(vector==NULL)
	{
		return E_NULL_PTR;
	}
	while(i++ < vector->m_numOfItems)
	{
		if(*(vector->m_arr[i])==*value)
		{
			count++;
		}
	}
	return count;

}*/




void vectorDestroy(Vector **vector)
{
	/* check if null */
	if(!vector)
		return;
	if(!(*vector)->m_arr)
		free((*vector)->m_arr);
	free(*vector);
	*vector=NULL;

}
