#include"CLI.h"

#include <iostream> 
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void CLI::runCli()
{
	string command;
	
	while(true)
	{
		screen.printToScreen("> cmd >>> ");
		command = screen.getUserInput();
		if(command == "quit")
		{
			cout << "GoodBye!!" << endl;
			break;
		}
		parser(command);
	
	}
	
	
}


void CLI::parser(string command)
{
	std::string delimiter = " ";
	std::vector<string> words;
	string com;
	size_t pos = 0;
	char temp = 0;
	std::string token;
	
	if(command == "labels")
	{

		m_analyzer->showLabel();
	}
	while ((pos = command.find(delimiter)) != std::string::npos) 
	{
		token = command.substr(0, pos);
		if(temp==0)
		{
			com = token;
			++temp;
		}
		else
		{
			words.push_back(token);
		}
		
		command.erase(0, pos + delimiter.length());
	}
	words.push_back(command);
	
	
	
	if(words.size()==0)
	{
		std::cout << "wrong command" << std::endl;
	}
	
	 if(com == "new")
	{
			
			m_analyzer->newDna(words);
			
	}
	else if(com == "load")
	{
		m_analyzer->loadDna(words);
	}
	else if(com == "dup")
	{
		m_analyzer->dupDna(words);
	}
	else if(com == "len")
	{
		m_analyzer->lenDna(words);
	}
	else if(com == "find")
	{
		
		m_analyzer->findDna(words);
	}
	else if(com == "findall")
	{
		m_analyzer->findAllDna(words);
	}
}









