#include"polimorphism.h"
#include<stdio.h>

void doPrePostFixer()
{
    printf("\n--- start doPrePostFixer() ---\n\n");
	PrePostFixer angleBrackets;
	_PrePostFixer_ctor(&angleBrackets,"<<< ", " >>>");
	PPF_print_text(&angleBrackets,"Hello World!");
	print_lc((&angleBrackets),((long)-777),'\0');
	print_lc((&angleBrackets),((long)350),'#');
	print_lc((&angleBrackets),((long)3.14),'\0');
   
    printf("\n--- end doPrePostFixer() ---\n\n");
    _PrePostFixer_dtor(&angleBrackets);
}

void doPrePostDollarFixer()
{
    printf("\n--- start doPrePostDollarFixer() ---\n\n");
    
   	PrePostDollarFixer asterisks;
   	_PrePostDollarFixer_cc_ctor(&asterisks,"***** ", " *****");
	print_PPDF_ic(&asterisks,-777,DEFAULT_SYMBOL);
	print_PPDF_ic(&asterisks,350, '#');
	print_PPDF_dc(&asterisks,3.14f, DEFAULT_SYMBOL);
    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    _PrePostDollarFixer_dtor(&asterisks);
}

void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
	PrePostFloatDollarFixer hashes;
	_PrePostFloatDollarFixer_ctor(&hashes,"### ", " ###");
	print_PPFDF_f(&hashes,-777);
	print_PPFDF_fc(&hashes,350, '#');
	print_PPFDF_f(&hashes,3.14f);
	PrePostDollarFixer hashes2;
	_PrePostFloatDollarFixer_ctor(&hashes2,"### ", " ###");
	print_PPFDF_f(&hashes,7.5);
	print_PPFDF_f(&hashes,100);
    printf("\n--- end doPrePostFloatDollarFixer() ---\n\n");
    _PrePostFloatDollarFixer_dtor(&hashes);
    _PrePostFloatDollarFixer_dtor(&hashes2);
}

int main()
{
	printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    /*doPrePostChecker();

    PrePostHashFixer hfix;
    runAsPrePostFixerRef(hfix);
    runAsPrePostDollarFixerRef(hfix);
    runAsPrePostDollarFixerObj(hfix);
    runAsPrePostHashFixerRef(hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();*/

    printf("\n--- End main() ---\n\n");

    return 0;
}
