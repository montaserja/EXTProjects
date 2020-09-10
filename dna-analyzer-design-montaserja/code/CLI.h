#ifndef __CLI_H__
#define __CLI_H__

#include"allSequences.h"
class CLI
{
	public:
		CLI();
		~CLI();
		void runCli();
	private:
	allSequences seqList;
};


inline CLI::CLI()
{
	
}
inline CLI::~CLI(){}



#endif /* __CLI_H__ */
