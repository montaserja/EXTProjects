#include "books.h"
#include "local_library.h"
#include <stdio.h>


bookCopy* check_forCopy(bookCopy** books_cpy,int serialNum,int number_of_books_cpy){
	for(int i=0;i<number_of_books_cpy;i++){
		if((**(books_cpy+i)).serial_number==serialNum){
			return *(books_cpy);
		}
	}
	return NULL;
}



int main(){
   init();
   extern book* books;
   int i;
   for(i=0;i<strlen((char*)books);i++){
   	print_book_real(*(books+i),i);
   }
   
   
  // bookCopy* book1,book2,book3,book4,book5,book6,book7,book8,book9,book10;
  int number_of_books_cpy=0;
  printf("insert the number of books copy you want to create\n");
  scanf("%d",&number_of_books_cpy);
   bookCopy** books_cpy=(struct bookCopy**)malloc(number_of_books_cpy*sizeof(struct bookCopy*));
   
   for(i=0;i<number_of_books_cpy;i++){
   
	   printf("insert internal book number to create a copy of a book %d:\n",i);
	   int internalCpy;
	   bool found=false;
	   if (scanf("%d", &internalCpy)== 1) {
	   	
		    for(int j=0;j<strlen((char*)books);j++){
		    	if((*(books+j)).internal_book_number==internalCpy){
		    		*(books_cpy+i)=(struct bookCopy*)malloc(sizeof(struct bookCopy));
		    		init_copy((*(books_cpy+i)),internalCpy);
		    		
		    		
		    		print_book((*(books_cpy+i)));
		    		
		    		found=true;
		    		break;
		    	}
		    	
		    }
		    if(found==false){
		    		perror("internal number not found");
		    		i--;
		    }
		    	found=false;
		} 
		else {
		    printf("Not an integer.\n");
		}
   }
   
   while(true){
	 	printf("1.Borrow a book-copy\n2.return a book-copy\n9.Exit\n\n");
	 	int choice=0;
	 	int serial=0;
	 	scanf("%d",&choice);
	 	
	 	switch (choice){
			case 1:
				printf("insert a serial number:");
				serial=0;
				scanf("%d",&serial);
				borrow_copy(check_forCopy(books_cpy,serial,number_of_books_cpy),true);
				break;

			case 2:
				printf("insert a serial number:");
				serial=0;
				scanf("%d",&serial);
				borrow_copy(check_forCopy(books_cpy,serial,number_of_books_cpy),false);
				break;
			case 9:
				printf("bye!!\n");
				//int len=strlen((char*)books);
				free(books);
				
				for(int i=0;i<number_of_books_cpy;i++){
					free(*(books_cpy+i));
				}
				free(books_cpy);
				books_cpy=NULL;
				free(books_cpy);
				exit(-1);
				break;
			default:
				perror("IT IS NOT A CHOISE PLEASE ENTER ONE OF THESE(1,2,9) AND TRY AGAIN");
		}  
   }

    
return 0;
}
