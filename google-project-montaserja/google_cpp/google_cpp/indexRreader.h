#ifndef __INDEXREADER_H__
#define __INDEXREADER_H__
#include<map>
#include<string>
#include<iostream>
#include<vector>
using std::vector;
using std::map;
using std::string;
using std::cout;
using std::endl;

class indexReader
{
	public:
		indexReader();
		bool make_dict_from_index(string words_path, string index_path);
	private:
		
		map < string, map< string,  vector<int>  > > words_dict;
		
};

#endif /*__INDEXREADER_H__*/

