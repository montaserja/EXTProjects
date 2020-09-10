#ifndef BOOKS_H
# define BOOKS_H
#include <stdbool.h>
#include <stdlib.h>  
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
enum zone{KIDS,HIGHSCHOOL,ADULT,DOCUMENTARY,COMICS};
enum Egenre{d,t,c,n};

typedef struct DRAMA
{
	int text_quality;
	int plot_quality;
}DRAMA;

typedef struct COMEDY
{
	int quality;
	char humor_type[1];
}COMEDY;

union genre {
   DRAMA drama;
   float THRILLER;
   COMEDY comedy;
   char NON_FICTION[4];
};

typedef struct book
{ 
    char* name;
    int internal_book_number;
    int promotion;
    enum zone type;
    union genre genre;
    enum Egenre genreType;
}book;

typedef struct bookCopy
{ 
    
    int internal_book_number;
    int serial_number;
    bool s_borrowed;
    int borrowing_times;
    uint8_t status;

}bookCopy;



char* get_book_name(book* book);
int get_book_Inumber(book* book);
int get_book_promotion(book* book);
int get_book_zone(book* book);

book* init_book(char* name,int internal_book_number,int promotion,int zone,union genre genre,int genreType);

char* get_zone_name(int zone);

void print_book(bookCopy* book_cpy);

void borrow_copy(bookCopy* book,bool is_borrowing);

void init_copy(bookCopy* book,int internal_book_number);

bool is_librarian_required(bookCopy* book_cpy);

bool is_bookbinder_required(bookCopy* book_cpy);

bool is_repairable(bookCopy* book_cpy);

bool is_ok(bookCopy* book_cpy);

bool is_useless(bookCopy* book_cpy);

bool are_in_same_condition(bookCopy* book1,bookCopy* book2);

bookCopy* create_copy(bookCopy* book);

void print_book_real(book book,int i);





#endif
