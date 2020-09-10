#ifndef __AUTOCOMPLETE_H__
#define __AUTOCOMPLETE_H__
#include<iostream>
#include<string>
using std::string;
#pragma once
class AutoCompleteData
{
private:
	string completed_sentence;
	string source_text;
	int offset;
	int score;
	// methods that you need to define by yourself

};
#endif /* __AUTOCOMPLETE_H__ */

