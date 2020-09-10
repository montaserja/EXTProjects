#include"polimorphism.h"
#include<stdio.h>
#include<stdlib.h>

void _TextFormatter_ctor(TextFormatter* const tFormat)
{
	tFormat->vtable_funcs.des=_TextFormatter_dtor;
	
}

void _TextFormatter_dtor(TextFormatter* const tFormat){}


/**************************************************************/
static int next_id=0;

static int getId() 
{
 return next_id++; 
}

void _DefaultTextFormatter_ctor(DefaultTextFormatter* const this)
{

	_TextFormatter_ctor(&this->tFormat);	
	this->tFormat.vtable_funcs.print=_DTFormat_print;
	*((int*)&this->id)=getId();
	printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}
void _DefaultTextFormatter_copy_ctor(DefaultTextFormatter* const this,const DefaultTextFormatter* const other)
{
	this->tFormat=other->tFormat;
	*((int*)&this->id)=other->id;
	printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
	
}
DefaultTextFormatter* const _DefaultTextFormatter_copy_ass(const DefaultTextFormatter* const other)
{
	DefaultTextFormatter temp;
	temp.tFormat=other->tFormat;
	*((int*)&temp.id)=other->id;
	 printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, temp.id);
	return &temp;
}

void _DTFormat_print(const void* const this,const char* text)
{
	printFunc("[DefaultTextFormatter::print(const char*)]");    
    printf("%s\n", text);
}

void _DefaultTextFormatter_dtor(DefaultTextFormatter* const this)
{
	printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
	_TextFormatter_dtor(&this->tFormat);
}

DefaultTextFormatter* generateFormatterArray()
{
	int i=0;
	DefaultTextFormatter* DTF = malloc(sizeof(DefaultTextFormatter)*3);
	for(;i<3;++i)
	{
		_DefaultTextFormatter_ctor(DTF+i);
	}
	return DTF;
}

/****************************************************************************/

void _PrePostFixer_ctor(PrePostFixer* const this, const char* prefix, const char* postfix)
{
	_DefaultTextFormatter_ctor(&this->vtable_PPF.dTFormat);
	this->vtable_PPF.dTFormat.tFormat.vtable_funcs.print=PPF_print_text;
	this->pre=prefix;
	this->post=postfix;
	printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}


void _PrePostFixer_dtor(PrePostFixer* const this)
{
	printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
	_DefaultTextFormatter_dtor(&this->vtable_PPF.dTFormat);
}

void PPF_print_text(const void* const this,const char* text)
{
	PrePostFixer* my_this=(PrePostFixer*)this;
	printFunc("[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", my_this->pre, text, my_this->post);
}
/*void print_lc(const void* const this,long num, char symbol)
{
	PrePostFixer* my_this=(PrePostFixer*)this;
}*/
/*char getDefaultSymbol(const void* const) ;*/



/**********************************************************************************************/


static const char DEFAULT_SYMBOL = '$';


void _PrePostDollarFixer_cc_ctor(PrePostDollarFixer* const this,const char* prefix, const char* postfix)
{
	_PrePostFixer_ctor(&this->PPF,prefix,postfix);
	this->PPF.vtable_PPF.print=print_PPDF_lc;
	printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(&(this->PPF)), getPostfix(&(this->PPF)));
}
void _PrePostDollarFixer_copy_ctor(PrePostDollarFixer* const this,const PrePostDollarFixer* const other)
{
	_DefaultTextFormatter_ctor(&this->PPF.vtable_PPF.dTFormat);
	this->PPF.vtable_PPF.dTFormat.tFormat.vtable_funcs.print=PPF_print_text;
	this->PPF.vtable_PPF.print=print_PPDF_lc;
	this->PPF.pre=other->PPF.pre;
	this->PPF.post=other->PPF.post;
	printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", getPrefix(&(this->PPF)), getPostfix(&(this->PPF)));
}
void _PrePostDollarFixer_dtor(PrePostDollarFixer* const this)
{
	
	  printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(&(this->PPF)), getPostfix(&(this->PPF)));
	  _PrePostFixer_dtor(&this->PPF);
	  
}



void print_PPDF_ic(const PrePostDollarFixer* const this,int num, char symbol)
{
	printFunc("[PrePostDollarFixer::print(int, char)]"); 
    printf("-->\n");
	this->PPF.vtable_PPF.print(this,(long)num,symbol);
}
void print_PPDF_lc(const void* const this,long num, char symbol) 
{
	PrePostDollarFixer* my_this=(PrePostDollarFixer*)this;
	printFunc("[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    print_num_lc((&(my_this->PPF)),num, symbol);
}
void print_PPDF_dc(const PrePostDollarFixer* const this,double num, char symbol)
{
	printFunc("[PrePostDollarFixer::print(double, char)]"); 
    printf("%s%c%f%s\n", getPrefix(&(this->PPF)), symbol, num,getPostfix(&(this->PPF)));
}


/***********************************************************************************************/

void _PrePostHashFixer_ctor(PrePostHashFixer* const this,int prc)
{
	_PrePostDollarFixer_cc_ctor(&this->PPDF,"===> ", " <===");
	this->precision=prc;
	printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", getPrefix(&(this->PPDF.PPF)), getPostfix(&(this->PPDF.PPF)), this->precision);

}
void _PrePostHashFixer_dtor(PrePostHashFixer* const this)
{
	_PrePostDollarFixer_dtor(&this->PPDF);
	printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(&(this->PPDF.PPF)), getPostfix(&(this->PPDF.PPF)));
}

void print_PPHF_ic(const PrePostHashFixer* const this,int num, char symbol)
{
	printFunc("[PrePostHashFixer::print(int, char)]"); 
    printf("-->\n");

    print_PPHF_dc(this,((double)num),symbol);
}
void print_PPHF_lc(const PrePostHashFixer* const this,long num, char symbol)
{
	printFunc("[PrePostHashFixer::print(long, char)]"); 
    printf("-->\n");
   	print_PPHF_dc(this,((double)num),symbol);
}
/*void print_PPHF_dc(const PrePostHashFixer* const this,double num, char symbol)
{

}
*/


/*********************************************************************************************************/

void _PrePostFloatDollarFixer_ctor(PrePostFloatDollarFixer* const this,const char* prefix, const char* postfix)
{
		_PrePostDollarFixer_cc_ctor(&this->PPDF,prefix, postfix);
		printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(&(this->PPDF.PPF)),getPostfix(&(this->PPDF.PPF)));
}
void _PrePostFloatDollarFixer_dtor(PrePostFloatDollarFixer* const this)
{
	printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(&(this->PPDF.PPF)), getPostfix(&(this->PPDF.PPF)));
	_PrePostDollarFixer_dtor(&this->PPDF);
	
}

void print_PPFDF_f(const PrePostFloatDollarFixer* const this,float num)
{
	printFunc("[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    print_PPFDF_fc(this,num, getDefaultSymbol_PPFDF());
}
void print_PPFDF_fc(const PrePostFloatDollarFixer* const this,float num, char symbol)
{
	printFunc("[PrePostFloatDollarFixer::print(float, char)]"); 

    printf("%s%c%.2F%s\n", getPrefix(&(this->PPDF.PPF)), symbol, num, getPostfix(&(this->PPDF.PPF)));
}


/********************************************************************************************************/



void _PrePostChecker_ctor(PrePostChecker* const this){
	_PrePostFloatDollarFixer_ctor(&this->PPFDF,"[[[[ ", " ]]]]");
	printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPostfix(&(this->PPFDF.PPDF.PPF)), getPostfix(&(this->PPFDF.PPDF.PPF)));
}

void _PrePostChecker_dtor(PrePostChecker* const this){
	printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPostfix(&(this->PPFDF.PPDF.PPF)), getPostfix(&(this->PPFDF.PPDF.PPF)));
	_PrePostFloatDollarFixer_dtor(&this->PPFDF);
    
}

void printThisSymbolUsingFunc_PPC(const PrePostChecker* const this ){
	printFunc("[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n", getDefaultSymbol_PPFDF());
}

void printThisSymbolDirectly_PPC(const PrePostChecker* const this ){
	printFunc("[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", getDefaultSymbol_PPFDF());
}

void printDollarSymbolByCastUsingFunc_PPC(const PrePostChecker* const this ){
	printFunc("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", getDefaultSymbol_PPDF());
}
void printDollarSymbolByScopeUsingFunc_PPC(const PrePostChecker* const this ){
	printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", getDefaultSymbol_PPDF());
}
void printDollarSymbolByCastDirectly_PPC(const PrePostChecker* const this ){
	printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", getDefaultSymbol_PPDF());
}
void printDollarSymbolByScopeDirectly(const PrePostChecker* const this ){
	printFunc("[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n",getDefaultSymbol_PPDF());
}

/**************************************************************************************************/


/*void _Multiplier_ctor(Multiplier* const this, int t){
	_DefaultTextFormatter_ctor(&this->DTF);
	this->DTF.tFormat.vtable_funcs.print = print_Multiplier;
	this->multiplierTimes = t;
    printf("--- Multiplier CTOR: times = %d\n", this->multiplierTimes);

}

void _Multiplier_dtor(Multiplier* const this){
    printf("--- Multiplier DTOR: times = %d\n", this->multiplierTimes);	
	_DefaultTextFormatter_dtor(&this->DTF);
}*/

void print_Multiplier(const void* const this , const char * text){
    int i;	
	printFunc("[Multiplier::print(const char*)]");
    for (i = 0; i < ((Multiplier*)this)->multiplierTimes; ++i)
        printf("%s", text);
    printf("\n");
}


























