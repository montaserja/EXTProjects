#include"CLI.h"

#include <iostream> 

using std::cin;
using std::cout;
using std::endl;
using std::string;

void CLI::runCli()
{
	string command;
	
	while(true)
	{
		getline(cin, command);
		
		if(command == "quit")
		{
			cout << "GoodBye!!" << endl;
			break;
		}else if(command.substr(0,3) == "new")
		{
			char* c=(char*)command.c_str();
			char * pch;
			char s[80];
			char s1[80];
			pch=strtok (c," ");
			if(pch)
				pch=strtok (NULL," ");
			else
				throw "no name new";
			strcpy(s,pch);
			pch=strtok (NULL," ");
			if(pch){
				strcpy(s1,pch);
				seqList.newseq(s,s1);
			}else
				seqList.newseq(s);
		}else if(command.substr(0,4) == "load")
		{
			char file_name[80] ="my_file_seq.txt";
			//char seq_name[80]="as";	
			seqList.loadseq(file_name);
		}
	
	}
	
	
}









