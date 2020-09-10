#ifndef __VECTOR_H__
#define __VECTOR_H__


#include<stddef.h>



typedef enum
{
	E_OK,
	E_NULL_PTR,
	E_UNDERFLOW,
	E_ALLOCATION_ERROR,
	E_BAD_INDEX
} ErrorCode;

typedef struct Vector Vector;

typedef void(*Print)(void *);
typedef void(*Func)(void *);

Vector* vectorCreate(size_t size);
void vectorDestroy(Vector **vector);

/* Adds an item at the end. Grows if needed (by * 2) */
ErrorCode vectorPush(Vector *vector, void* value);

/* Adds an item at a certain position and shifts. Grows if needed (by * 2) */
ErrorCode vectorInsert(Vector *vector, void* value, size_t index);

/* Clears the item at the end. Grows if needed (by * 2) */
ErrorCode vectorPop(Vector *vector, void **res);

/* Clears an item at a certain position and shifts. */
ErrorCode vectorRemove(Vector *vector, size_t index, void **res);

ErrorCode vectorGetElement(const Vector *vector, size_t index, void **res);
ErrorCode vectorSetElement(Vector *vector, size_t index, void *value);

size_t vectorGetSize(const Vector *vector);
size_t vectorGetCapacity(const Vector *vector);

/* Counts how many instances of a given value there are. */
size_t vectorCount(const Vector *vector, void *value);

size_t vectorForEach(Vector *vector,Func);

#ifdef _DEBUG
void vectorPrint(Vector *vector,Print print);
#endif /* _DEBUG */

#endif /* __VECTOR_H__ */


