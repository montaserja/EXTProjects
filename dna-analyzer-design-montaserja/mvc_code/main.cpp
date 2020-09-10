
#include<string>
#include"model/dna//dna_sequence/Dna_N_ID.h"
#include"model/database/database.h"
#include"controller/CLI.h"

using std::cout;
using std::endl;

int main()
{
	database data;
	CLI cli(&data);
	cli.runCli();

	/*char c[80]="CACCCCAAA";
	DnaSequence s(c);
	Dna_N_ID dnaWithName(&s,"first" , 1);
	cout << dnaWithName << endl;*/
	
	/*string str="ACC";
	DnaSequence stringDna(str);
	cout << stringDna << endl;
	
	DnaSequence cpyDna=stringDna;
	cout << cpyDna << endl;
	cout << stringDna << endl;
	cpyDna=s;
	cout << cpyDna << endl;
	cout << stringDna << endl;
	//cpyDna[0]='A';
	cout << cpyDna[0] << endl;
	
	DnaSequence slice=s.slice(1,4);
	
	cout << slice << endl;
	
	
	DnaSequence pair=slice.pair();
	cout << pair <<endl;
	
	char cPtr[80]="ATACCT";
	DnaSequence seq(cPtr);
	
	
	cout << seq.find(stringDna) << endl;
	
	*/
	
	
	
	
	return 0;
}

