#include "books.h"



const static char* zoneName[5] = { "kids", "highschool","adult","documentary","comics" };



book* init_book(char* name,int internal_book_number,int promotion,int zone,union genre genre,int genreType){
    book* book;
    if(strlen(name)>=50 || internal_book_number>50000||internal_book_number<0||promotion>100||promotion<-100){
    return NULL;
    }
    
    book=(struct book*)malloc(sizeof(struct book));
    
    //book->name=(char*)malloc((strlen(name)*sizeof(char))+1);
    
    //strcpy(book->name, name);
    book->name=name;
    book->internal_book_number=internal_book_number;
    book->promotion=promotion;
    book->type=zone;
    book->genre=genre;
    book->genreType=genreType;
return book;
}

char* get_book_name(book* book){

return book->name;
}

int get_book_Inumber(book* book){
return book->internal_book_number;
}

int get_book_promotion(book* book){
return book->promotion;
}

int get_book_zone(book* book){
return book->type;
}


char* get_zone_name(int zone){
return (char*)zoneName[zone];
}

void print_book(bookCopy* book_cpy){
    if(book_cpy!=NULL){
        printf("internal book number: %d\nserial number: %d\nis borrowed:%d\n",book_cpy->internal_book_number,book_cpy->serial_number,book_cpy->s_borrowed);
        if(is_librarian_required(book_cpy)){
        	printf("need a librarian\n");
        }else{
        	printf("no need for librarian\n");
        }
        if(is_bookbinder_required(book_cpy)){
        	printf("need a bookbinder\n");
        }else{
        	printf("no need of bookbinder\n");
        }
        if(is_repairable(book_cpy)){
        	printf("the book is repairable!!\n");
        }else{
        	printf("the book is not repairable!\n");
        }
        
        if(is_ok(book_cpy)){
        	printf("the book is ok\n\n");
        }
        if(is_useless(book_cpy)){
        	printf("the book is useless\n\n");
        }
    }else
    	printf("book is null \n");
}

void borrow_copy(bookCopy* book,bool is_borrowing){
	if(book==NULL){
		perror("book copy is NULL(not found)");
	}else
		if(book->s_borrowed !=is_borrowing){
		    book->s_borrowed=is_borrowing;
		    if(is_borrowing==true){
		    	book->borrowing_times++;
		    }   
		}else{
		    perror("Error printed by perror");
		}
}

void init_copy(bookCopy* book,int internal_book_number){
    book->internal_book_number=internal_book_number;
    book->s_borrowed=false;
    static int serial_num= 10000;
    book->serial_number=serial_num;
    serial_num++;
    book->borrowing_times=0;
    book->status=0x3f;//0011 1111
}


bool is_librarian_required(bookCopy* book_cpy){
	
	if((book_cpy->status & 0x09)==0x09){
		return false;
	}
return true;
}


bool is_bookbinder_required(bookCopy* book_cpy){
	if((book_cpy->status & 0x34)==0x34){
			return false;
		}
	return true;
}


bool is_repairable(bookCopy* book_cpy){
	if((book_cpy->status & 0x24)==0x24){
				return true;
			}
		return false;
}

bool is_ok(bookCopy* book_cpy){
	if((book_cpy->status & 0x3f)==0x3f){
				return true;
			}
		return false;
}


bool is_useless(bookCopy* book_cpy){
	unsigned int count = 0; 
	unsigned int n=book_cpy->status;
  while (n) 
  { 
    count += n & 1; 
    n >>= 1; 
  }
  if(count<2){
  	return true;
  }
return false;
}




bool are_in_same_condition(bookCopy* book1,bookCopy* book2){
	if(book1->status==book2->status){
		return true;
	}
	return false;
}




bookCopy* create_copy(bookCopy* book){
	bookCopy* copy=(bookCopy*)malloc(sizeof(bookCopy));
	init_copy(copy,book->internal_book_number);
	return copy;
}

static void print_drama(book* book){
	printf("text quality is: %d , plot quality is: %d\n",book->genre.drama.text_quality,book->genre.drama.plot_quality);
}
static void print_thriller(book* book){
	printf("%lf\n",book->genre.THRILLER);
}
static void print_comedy(book* book){
	printf("quality of the humor : %d , the humor type is : %s\n",book->genre.comedy.quality,book->genre.comedy.humor_type);

}
static void print_non_fiction(book* book){
	printf("the field of the book is: %s",book->genre.NON_FICTION);

}
static void print_genre(book* book){
	 switch (book->genreType){
		case d:
		    print_drama(book);
		    break;

		case t:
		    print_thriller(book);
		    break;
		case c:
		    print_comedy(book);
		    break;
		case n:
		    print_non_fiction(book);
		    break;
		    
		default:
		    perror("genreType error");
	}
}

void print_book_real(book book,int i){
printf("Book %d -> Name: %s ,internal number: %d ,promotion: %d ,type: %d\n",i,book.name,book.internal_book_number,book.promotion,book.type);

print_genre(&book);
printf("\n\n");

}





    


