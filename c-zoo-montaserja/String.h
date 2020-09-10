#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>

class String {

public:
	String();
	String(const String &);
	String(const char *);
	~String();
	size_t length();
	char& operator[] (unsigned int);
	//const char operator[] (unsigned int) const;
	String& operator =(const String&);
	void operator += (const String&);
	friend String operator+(const String& str1,const String& str2);
	bool operator==(const String &);
	bool operator<=(const String &);
	bool operator>=(const String &);
	bool operator<(const String &);
	bool operator>(const String &);
	friend std::ostream & operator <<(std::ostream &, const String &);
	
private:
	size_t size;
	char *str;

	int strCmp(const char* s1, const char* s2);
};



#endif /* __STRING_H__ */
