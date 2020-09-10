#include"String.h"
#include"stdlib.h"
using std::cout;
using std::endl;

String::String() :size(0),str(NULL){}

String::String(const char * s)
{
	
	size_t s_size = 0;
	const char *save_ptr = s;
	
	//size of s
	while(*s++){++s_size;}
	size=s_size+1;
	str = new char[size];
	size_t i=0;
	
	//copy s to str
	while(i < size-1)
	{
		str[i]=save_ptr[i];
		++i;
	}
	
	str[i]='\0';
	
}

String::String(const String &s):size(s.size)
{
	str=new char[s.size];
	size_t i = 0;
	while(i < s.size)
	{
		str[i]=s.str[i];

	++i;
	}
}

char& String::operator[] (unsigned int index)
{
	if(index > length())
	{
		throw "overflow_error";
	}
	char &c_index = str[index];
	return c_index;
	
}

size_t String::length()
{
	return size-1;
}

String::~String()
{
	delete[] str;
}

String &String::operator =(const String& s)
{
	if(this != &s)
	{
		size=0;
		if(str)
		{
			delete[] str;
		}

		str=new char[s.size];
		
		while(size < s.size)
		{
			str[size]=s.str[size];
			size++;
		}
	}
return *this;

}

String operator+(const String& str1,const String& str2){
	if (str2.size == 0 )
		return (str1);
	if (str1.size == 0 )
		return (str2);
	char *tmpmain = new char[ (str1.size) + (str2.size) + 1 ];
	size_t i = 0;
	while (i < str1.size) {
		tmpmain[i]=str1.str[i];
		++i;
	}
	size_t j = 0;
	while (j < str2.size) {
		tmpmain[i++]=str2.str[j++];
	}
	tmpmain[i]='\0';
	String new_str(tmpmain);
	if (i>0)
		delete [] tmpmain;
	return new_str;
	
}

void String::operator += (const String& s)
{
	size_t new_size = (size+s.size-1);
	char *new_str=new char[new_size];
	size_t i=0;

	while(i < size-1) 
	{
		new_str[i]=str[i];
		++i;
	}
	while(i < new_size)
	{
		new_str[i]=s.str[i-size+1];
		++i;
	};

	delete[] str;
	
	str=new_str;
	size=new_size;
	
}

int String::strCmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

bool String::operator==(const String &s)
{
	char* my_temp=str;
	char* s_temp=s.str;
	if(strCmp(my_temp,s_temp)!=0)
		return false;
	return true;
}

bool String::operator<=(const String &s)
{
	char* my_temp=str;
	char* s_temp=s.str;
	if(strCmp(my_temp,s_temp)<=0)
		return true;
	return false;
}

bool String::operator>=(const String &s)
{
	char* my_temp=str;
	char* s_temp=s.str;
	if(strCmp(my_temp,s_temp)>=0)
		return true;
	return false;
}

bool String::operator<(const String &s)
{
	char* my_temp=str;
	char* s_temp=s.str;
	if(strCmp(my_temp,s_temp)<0)
		return true;
	return false;
}

bool String::operator>(const String &s)
{
	char* my_temp=str;
	char* s_temp=s.str;
	if(strCmp(my_temp,s_temp)>0)
		return true;
	return false;
}

std::ostream & operator <<(std::ostream &os, const String &s)
{
    os << s.str;
    return os;

}















