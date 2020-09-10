#include"String.h"
using namespace std;
int main()
{

String s("aaaa");
String s3;
s3=s;
String s1=s;
cout<< s1.length()<<endl;
//s1[2]='n';
cout<< s1[2]<<endl;

String s2="ddd";
//s2[2]=s1[2];
s1=s2=s2;
s1+=s2;
cout << s1 << endl;
cout<< s3 <<endl;

return 0;
}
