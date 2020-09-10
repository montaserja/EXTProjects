#include"factory.h"
#include"box.h"


int main()
{
	Box b;
	Factory f(3,4,&b);
	f.start_threads();
	return 0;
}
