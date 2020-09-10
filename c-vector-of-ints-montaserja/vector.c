#include"vector.h"


struct Vector
{
	int *m_arr;
	size_t m_length;
	size_t m_numOfItems;
};

Vector* vectorCreate(size_t length)
{
	Vector *vector=malloc(sizeof(Vector));
	vector->m_arr=malloc(length*sizeof(int));
	vector->m_length=length;
	vector->m_numOfItems=0;
	return vector;
}

ErrorCode vectorPush(Vector *vector, int value)
{
	if(vector==NULL)
	{
		return E_NULL_PTR;
	}
	if((vector->m_numOfItems) >= (vector->m_length))
	{
		int *tmp =realloc(vector->m_arr, sizeof(int)*(vector->m_length*2));
		if(tmp==NULL)
		{
			return E_ALLOCATION_ERROR;
		}
		vector->m_arr = tmp;
		vector->m_length*=2;
	}
	vector->m_arr[vector->m_numOfItems]=value;
	vector->m_numOfItems++;

	
return E_OK;
}


void vectorPrint(Vector *vector)
{	
	int i=0;
	
	if(vector==NULL)
	{
		return;
	}
	while(i<vector->m_numOfItems)
	{
		printf("%d\t",vector->m_arr[i++]);
	}
	printf("\n");

}

ErrorCode vectorPop(Vector *vector, int *res)
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


ErrorCode vectorGetElement(const Vector *vector, size_t index, int *res)
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

ErrorCode vectorSetElement(Vector *vector, size_t index, int value)
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

ErrorCode vectorInsert(Vector *vector, int value, size_t index)
{
	int temp;
	size_t i;
	if(index >= vector->m_numOfItems)
	{
		return E_BAD_INDEX;
	}
	if((vector->m_numOfItems) >= (vector->m_length))
	{
		int *tmp =realloc(vector->m_arr, sizeof(int)*(vector->m_length*2));
		if(tmp==NULL)
		{
			return E_ALLOCATION_ERROR;
		}
		vector->m_arr = tmp;
		vector->m_length*=2;
	}
	temp=vector->m_arr[index];
	vector->m_arr[index]=value;
	vector->m_numOfItems++;
	i=vector->m_numOfItems;
	while(i>index)
	{
		vector->m_arr[i]=vector->m_arr[i-1];
		--i;
	}
	vector->m_arr[i+1]=temp;
	return E_OK;
}


ErrorCode vectorRemove(Vector *vector, size_t index, int *res)
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

size_t vectorCount(const Vector *vector, int value)
{
	
	size_t count=0,i=0;
	if(vector==NULL)
	{
		return E_NULL_PTR;
	}
	while(i++ < vector->m_numOfItems)
	{
		if(vector->m_arr[i]==value)
		{
			count++;
		}
	}
	return count;

}

void vectorDestroy(Vector **vector)
{
	
	free((*vector)->m_arr);
	free(*vector);
	*vector=NULL;

}
