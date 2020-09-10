#include"DnaSequence.h"

size_t DnaSequence::id=1;

DnaSequence DnaSequence::slice(size_t from,size_t to)
{
	if(from > to)
	{
		from ^= to;
		to ^= from;
		from ^= to;
	}
	size_t diffrence=to-from;
	
	if(to > size || from > size)
	{
		throw std::invalid_argument("index out of range");
	}
	size_t i=0;
	char* my_char = new char[diffrence+1] ;
	
	for(;i<diffrence;++i)
	{
		my_char[i]=m_nuc_arr[i+from]->getNuc();
	}
	my_char[i]='\0';
	DnaSequence dna(my_char);
	
	delete [] my_char;
	return dna;
	
}



size_t DnaSequence::find(DnaSequence & subSeq) const
{
	if(subSeq.getSize() > size)
		throw "not find";
		
	size_t i;
    for (i = 0 ; i <= (size)-(subSeq.getSize()); ++i)
    {
    	size_t j;
        for ( j = 0; j < subSeq.getSize() ; ++j)
            if ( m_nuc_arr[i + j]->getNuc() != subSeq.m_nuc_arr[j]->getNuc() )
                break;

        if (j == subSeq.getSize())
            return i+1;
    }
    return -1;

}









std::list<int> DnaSequence::findAll(DnaSequence& dnaSeq){
	if ( dnaSeq.getSize() > size )
		return std::list<int>();
 
    std::list<int> subs;
    for (size_t i = 0; i <= size-(dnaSeq.getSize()); ++i) 
    {   
        size_t j; 
        for (j = 0; j < (dnaSeq.getSize()); j++) 
            if ( m_nuc_arr[i + j]->getNuc() != dnaSeq.m_nuc_arr[j]->getNuc() )
                break; 
   
        if (j == dnaSeq.getSize())   
        { 
           subs.push_back(int(i+1));
           j = 0;
        } 
    } 
    return subs;
}






std::list<DnaSequence> DnaSequence::FindConsensusSequences(){ 
	DnaSequence startSeq((char*)"ATG");
	DnaSequence endSeq[] = {DnaSequence((char*)"TAG"),DnaSequence((char*)"TAA"),DnaSequence((char*)"TGA")};
	std::list<DnaSequence> result;
	
	long pos = find(startSeq);
	while ( pos != -1 ){
		long min_end_pos = -1 ;
		for(long i =0 ; i<3;i++){	
			long ep = find(endSeq[i]);
			if (min_end_pos == -1 || ( ep!=-1 && ep < min_end_pos))
				min_end_pos = ep;
		}
		if (min_end_pos != -1){
			result.push_back(slice(pos,min_end_pos+3));
		    pos = slice(pos,getSize()).find(startSeq);
		
		}else
			break;	
	}
	return result;
}











