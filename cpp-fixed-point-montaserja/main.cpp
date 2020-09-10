#include"Price.h"
#include"tests.h"

using std::cout;
using std::endl;

int main()
{
	cout << "--------start main--------" << endl;
	test_PLUS_EQUAL_OP();
	test_MINUS_EQUAL_OP();
	test_MULT_EQUAL_OP();
	test_ISEQUAL_OP();
	test_ISNOTEQUAL_OP();
	test_BIGGER_OP();
	test_SMALLER_OP();
	cout << "--------end main--------" << endl;
	return 0;
}
