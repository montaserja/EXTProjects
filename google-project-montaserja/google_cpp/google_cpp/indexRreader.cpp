#include "indexRreader.h"
#include <fstream>
#include <sstream> 
using std::ifstream;

indexReader::indexReader()
{
}

bool indexReader::make_dict_from_index(string words_path,string index_path)
{
	string line;
	ifstream myfile(words_path);
	map <string, int> words_linesNum;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			int pos = line.find(",");
			string word = line.substr(0, pos);
			string line_num = line.substr(pos+1, line.find("\n"));
			std::stringstream ss(line_num);
			int num = 0;
			ss >> num;
			words_linesNum[word] = num;
		}
		myfile.close();
	}
	else {
		cout << "Unable to open words file";
		return false;
	}
	ifstream myindexfile(index_path);
	if (myindexfile.is_open())
	{

		for (map<string, int>::iterator it = words_linesNum.begin(); it != words_linesNum.end(); ++it) {
			myindexfile.seekp(10);
			getline(myindexfile, line);
			cout << line << endl;
			return false;
			while (getline(myindexfile, line))
			{
				int pos = line.find(",");
				string book = line.substr(0, pos);
				string temp = line.erase(0, pos+1);
				vector<int> temp_v;
				while (temp!="") {
					pos = line.find(",");
					std::stringstream ss(line.substr(0, pos));
					int num = 0;
					ss >> num;
					temp_v.push_back(num);
					temp = line.erase(0, pos + 1);
				}
				words_dict[it->first][book] = temp_v;
				
				return false;
			}

		}
	}
	else
	{
		cout << "cannot open index file" << endl;
		return false;
	}

	return true;
}
