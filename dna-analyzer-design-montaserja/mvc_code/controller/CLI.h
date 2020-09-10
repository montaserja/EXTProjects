#ifndef __CLI_H__
#define __CLI_H__

#include"commands/commandAnalyzer.h"
#include"../view/screen.h"
class CLI
{
	public:
		CLI(database*);
		~CLI();
		void runCli();
		void parser(string);
	private:
		//database* m_database;
		Screen screen;
		commandAnalyzer* m_analyzer;
	//allSequences seqList;
};


inline CLI::CLI(database* database) : m_analyzer(new commandAnalyzer(database))
{
	
}
inline CLI::~CLI()
{
	delete m_analyzer;
}



#endif /* __CLI_H__ */
