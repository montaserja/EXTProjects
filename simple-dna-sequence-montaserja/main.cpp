#include"DnaSequence.h"
#include<string>

using std::cout;
using std::endl;

int main()
{


	char c[80]="CACCCCAAA";
	DnaSequence s(c);
	cout << s << endl;
	
	string str="ACC";
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
	
	
	
	
	
	
	return 0;
}

