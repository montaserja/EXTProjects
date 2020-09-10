#ifndef LOCAL_LIBRARY_H
#define LOCAL_LIBRARY_H
#include "books.h"
const book* getFirst();
int howManyBooks();

char* getBookName(int internal_book_number);

void init();


#endif
