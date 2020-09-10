#include "local_library.h"

book* books;

void init(){

union genre genre;
genre.drama.text_quality=50;
genre.drama.plot_quality=50;
book* book1=init_book("Sun Don't Shine",1001,40,ADULT,genre,d);
book* book2=init_book("Irma la dos",1002,-100,DOCUMENTARY,genre,d);
book* book3=init_book("Starship Troopers: Invasion",1003,-68,KIDS,genre,d);
book* book4=init_book("Year of the Jellyfish",1004,5,ADULT,genre,d);
book* book5=init_book("After Life",1005,-95,DOCUMENTARY,genre,d);
book* book6=init_book("Rest Stop",1007,20,HIGHSCHOOL,genre,d);
book* booksCpy[]= {book1,book2,book3,book4,book5,book6};
books=(book*)malloc(6*sizeof(book));
for(int i=0;i<6;i++){
*(books+i)=*booksCpy[i];
free(booksCpy[i]);
}
}

const book* getFirst(){
    return books;
}

int howManyBooks(){
return sizeof(books);
}

char* getBookName(int internal_book_number){

    for(int i=0;i<sizeof(books);i++){
        if(books[i].internal_book_number==internal_book_number)
            return books[i].name;
    }
return 0;

}

