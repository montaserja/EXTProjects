#include"tests.h"
#include"Price.h"

using std::cout;
using std::endl;

void test_PLUS_EQUAL_OP()
{
	cout << "\n--------start test_PLUS_EQUAL_OP--------" << endl;
	Price p1(55,82);
	cout << p1 << endl;
	Price p2(55,82);
	cout << p2 << endl;
	
	p2+=p1;
	cout << "p2+=p1 :" <<p2 << endl;
	if((double)p2==111.64)
		cout << "\nsuccess" << endl;
	else
		cout << "\nfailed" << endl;
	
	cout << "--------end test_PLUS_EQUAL_OP--------\n" << endl;
	
	
		
}

void test_MINUS_EQUAL_OP()
{
	cout << "\n--------start test_MINUS_EQUAL_OP--------" << endl;
	Price p1(55,82);
	cout << p1 << endl;
	Price p2(55,82);
	cout << p2 << endl;
	
	p2-=p1;
	cout << "p2-=p1 :" <<p2 << endl;
	if((double)p2==0)
		cout << "\nsuccess" << endl;
	else
		cout << "\nfailed" << endl;
	
	cout << "--------end test_MINUS_EQUAL_OP--------\n" << endl;	
}

void test_MULT_EQUAL_OP()
{
	cout << "\n--------start test_MULT_EQUAL_OP--------" << endl;
	Price p1(55,82);
	cout << p1 << endl;
	Price p2(55,82);
	cout << p2 << endl;
	
	p2*=p1;
	cout << "p2*=p1 :" <<p2 << endl;
	if((double)p2==3115.87)
		cout << "\nsuccess" << endl;
	else
		cout << "\nfailed" << endl;
	
	cout << "--------end test_MULT_EQUAL_OP--------\n" << endl;	
}




void test_ISEQUAL_OP()
{
	cout << "\n--------start test_ISEQUAL_OP--------" << endl;
	Price p1(55,82);
	cout << p1 << endl;
	Price p2(55,82);
	cout << p2 << endl;
	
	cout << ((p1==p2) ? " op == success":"op == failed") << endl;
	
	cout << "--------end test_ISEQUAL_OP--------\n" << endl;
	
	
		
}

void test_ISNOTEQUAL_OP()
{
	cout << "\n--------start test_ISNOTEQUAL_OP--------" << endl;
	Price p1(55,82);
	cout << p1 << endl;
	Price p2(2,82);
	cout << p2 << endl;
	
	cout << ((p1!=p2) ? " op != success":"op != failed") << endl;
	
	cout << "--------end test_ISNOTEQUAL_OP--------\n" << endl;		
}

void test_BIGGER_OP()
{
	cout << "\n--------start test_BIGGER_OP--------" << endl;
	Price p1(55,82);
	cout << p1 << endl;
	Price p2(2,82);
	cout << p2 << endl;
	
	cout << ((p1>p2) ? " op> success":"op > failed") << endl;
	
	cout << "--------end test_BIGGER_OP--------\n" << endl;	

}
void test_SMALLER_OP()
{
	cout << "\n--------start test_BIGGER_OP--------" << endl;
	Price p1(55,82);
	cout << p1 << endl;
	Price p2(222,82);
	cout << p2 << endl;
	
	cout << ((p1<p2) ? " op< success":"op< failed") << endl;
	
	cout << "--------end test_BIGGER_OP--------\n" << endl;	

}



















