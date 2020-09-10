#ifndef __SCREEN_H__
#define __SCREEN_H__

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Screen{
	
	public:
		void printToScreen(string);
		string getUserInput();


};

inline void Screen::printToScreen(string s)
{
	std::cout << s;
}

inline string Screen::getUserInput()
{
	string command;
	getline(cin, command);
	return command;
}

#endif /* __SCREEN_H__ */
