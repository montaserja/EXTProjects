#include"String.h"
	String::String(){}
	String::String(const String::String &){}
	String::String(const char *){}
	String::~String(){}
	size_t String::length(){}
	char& String::operator[] (unsigned int){}
	//const char String::operator[] (unsigned int) const{}
	String& String::operator=(const String&){}
	void String::operator+=(const String&){}
	bool String::operator==(const String &){}
	bool String::operator<=(const String &){}
	bool String::operator>=(const String &){}
	bool String::operator<(const String &){}
	bool String::operator>(const String &){}
	std::ostream & String::operator<<(std::ostream &, const String &){}
	int String::strCmp(const char* s1, const char* s2){}
