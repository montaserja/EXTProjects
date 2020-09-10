#ifndef __POLIMORPHISM_H__
#define __POLIMORPHISM_H__

#define printFunc(fname) printf("%-60s | ", (const char*)(fname))


/***************************************** TextFormatter *******************/

typedef struct TextFormatter TextFormatter;
typedef void (*destructorPtr)(TextFormatter* const tFormat);
typedef void (*printPtr)(const void* const,const char* text);

typedef struct TextFormatter_Funcs
{
	destructorPtr des;
	printPtr print;
	
}TextFormatter_Funcs;

struct TextFormatter
{
	TextFormatter_Funcs vtable_funcs;
	
};


void _TextFormatter_ctor(TextFormatter* const tFormat);
void _TextFormatter_dtor(TextFormatter* const tFormat);

/*********************************** DefaultTextFormatter ****************************************/

static int next_id;
static int getId();

typedef struct DefaultTextFormatter
{
	TextFormatter tFormat;
	const int id;
} DefaultTextFormatter;

void _DefaultTextFormatter_ctor(DefaultTextFormatter* const);
void _DefaultTextFormatter_copy_ctor(DefaultTextFormatter* const,const DefaultTextFormatter* const);
DefaultTextFormatter* const _DefaultTextFormatter_copy_ass(const DefaultTextFormatter* const);
void _DefaultTextFormatter_dtor(DefaultTextFormatter* const);
void _DTFormat_print(const void* const,const char* text);
DefaultTextFormatter* generateFormatterArray();

/****************************************PrePostFixer****************************************************/
typedef void (*PPF_print_lc)(const void* const,long num, char symbol);
typedef char (*DSymbol)(const void* const);

typedef struct PrePostFixer_Func
{
	DefaultTextFormatter dTFormat;
	PPF_print_lc print;
	DSymbol defaultSymbol;
}PrePostFixer_Func;

typedef struct PrePostFixer
{
	PrePostFixer_Func vtable_PPF;
	const char* pre;
    const char* post;

}PrePostFixer;

void _PrePostFixer_ctor(PrePostFixer* const , const char* prefix, const char* postfix);
void _PrePostFixer_dtor(PrePostFixer* const);
void PPF_print_text(const void* const,const char* text);
#define print_num_l(this,num) \
    printFunc("[PrePostFixer::print_num(long)]"); \
    printf("%s%ld%s\n", this->pre, num, this->post);

#define print_num_lc(this,num,symbol)\
	printFunc("[PrePostFixer::print_num(long, char)]"); \
    printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
    
#define print_lc(PPF,num,symbol) \
	printFunc("[PrePostFixer::print(long, char)]");\
    printf("-->\n"); \
    if (symbol)  \
    	{print_num_lc(PPF,num, symbol);}\
    else \
        print_num_l(PPF,num);
        
#define getDefaultSymbol() '\0'

#define getPrefix(this) ((PrePostFixer*)this)->pre
#define getPostfix(this) ((PrePostFixer*)this)->post

    
    
/*****************************************PrePostDollarFixer***********************************************************/
static const char DEFAULT_SYMBOL;
typedef struct PrePostDollarFixer
{
	PrePostFixer PPF;

}PrePostDollarFixer;

void _PrePostDollarFixer_cc_ctor(PrePostDollarFixer* const,const char* prefix, const char* postfix);
void _PrePostDollarFixer_copy_ctor(PrePostDollarFixer* const,const PrePostDollarFixer* const other);
void _PrePostDollarFixer_dtor(PrePostDollarFixer* const);
void print_PPDF_ic(const PrePostDollarFixer* const,int num, char symbol);
void print_PPDF_lc(const void* const,long num, char symbol) ;
void print_PPDF_dc(const PrePostDollarFixer* const,double num, char symbol);
#define getDefaultSymbol_PPDF() DEFAULT_SYMBOL

/***********************************************PrePostHashFixer**********************************************************/


typedef struct PrePostHashFixer
{
	PrePostDollarFixer PPDF;
	int precision;

}PrePostHashFixer;

void _PrePostHashFixer_ctor(PrePostHashFixer* const,int prc);
void _PrePostHashFixer_dtor(PrePostHashFixer* const);
void print_PPHF_ic(const PrePostHashFixer* const,int num, char symbol);
void print_PPHF_lc(const PrePostHashFixer* const,long num, char symbol);
#define print_PPHF_dc(this,num,symbol)\
	 printFunc("[PrePostHashFixer::print(double, char)]"); \
    printf("%s[%c%.*f]%s\n", getPrefix(&((this)->PPDF.PPF)), symbol, this->precision, num, getPostfix(&((this)->PPDF.PPF)));

#define getDefaultSymbol_PPHF() '#'


/*****************************************PrePostFloatDollarFixer****************************************************/

typedef struct PrePostFloatDollarFixer
{
	PrePostDollarFixer PPDF;
}PrePostFloatDollarFixer;

void _PrePostFloatDollarFixer_ctor(PrePostFloatDollarFixer* const,const char* prefix, const char* postfix);
void _PrePostFloatDollarFixer_dtor(PrePostFloatDollarFixer* const);
void print_PPFDF_f(const PrePostFloatDollarFixer* const,float num);
void print_PPFDF_fc(const PrePostFloatDollarFixer* const,float num, char symbol) ;
#define getDefaultSymbol_PPFDF() '@'


/*********************************************PrePostChecker**************************************************************/

typedef struct{
	PrePostFloatDollarFixer PPFDF;
}PrePostChecker;

void _PrePostChecker_ctor(PrePostChecker* const);

void _PrePostChecker_dtor(PrePostChecker* const);

void printThisSymbolUsingFunc_PPC(const PrePostChecker* const);

void printThisSymbolDirectly_PPC(const PrePostChecker* const);

void printDollarSymbolByCastUsingFunc_PPC(const PrePostChecker* const);

void printDollarSymbolByScopeUsingFunc_PPC(const PrePostChecker* const);

void printDollarSymbolByCastDirectly_PPC(const PrePostChecker* const);

void printDollarSymbolByScopeDirectly(const PrePostChecker* const);

/*****************************************************Multiplier*****************************************************/


typedef struct {
	DefaultTextFormatter DTF;
	int multiplierTimes;
}Multiplier;

#define _Multiplier_ctor(this,t)\
	_DefaultTextFormatter_ctor(&this->DTF);\
	this->DTF.tFormat.vtable_funcs.print = print_Multiplier;\
	this->multiplierTimes = t;\
    printf("--- Multiplier CTOR: times = %d\n", this->multiplierTimes);



#define _Multiplier_dtor(this)\
    printf("--- Multiplier DTOR: times = %d\n", this->multiplierTimes);	\
	_DefaultTextFormatter_dtor(&this->DTF);


/*void _Multiplier_ctor(Multiplier* const , int t);

void _Multiplier_dtor(Multiplier* const );*/

void print_Multiplier(const void* const , const char * const);

#define getTimes_Multiplier(this) ((Multiplier*)this)->multiplierTimes
#define setTimes_Multiplier(this,t) ((Multiplier*)this)->multiplierTimes = t











#endif /* __POLIMORPHISM_H__ */
