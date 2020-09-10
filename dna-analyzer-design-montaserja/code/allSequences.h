#ifndef __ALLSEQUENCES_H__
#define __ALLSEQUENCES_H__

#include <vector>
#include"DnaSequence.h"
using std::vector;

#define seqVector vector<DnaSequence>

class allSequences
{
	public:
		allSequences();
		~allSequences();
		void newseq(char* seq,char* name=NULL);
		void loadseq(char* file_name,char* name=NULL);
	
	private:
		seqVector sequences;
		size_t m_size;
		size_t default_name_id;
};

inline allSequences::allSequences():m_size(0),default_name_id(1){}
inline allSequences::~allSequences(){}

#endif /* __ALLSEQUENCES_H__ */ 

