#include"animal.h"

using std::cout;
using std::endl;
#include <sstream>

std::ostream& operator<<(std::ostream& out,const Animal& animal)
{
out << animal.printDetails() << animal.print_children_Details();
return out;
}

String Animal::printDetails() const
{
	std::stringstream ss;
	ss << "Name: " << getName()<< "\nspecies : " << getSpecies() << "\nlife expectancy: " << static_cast<int>(getLifeExpectancy()) << "\ncontinents: " <<getContinent()
		<< "\nFood: " << getFoodTypes() << "\nspeed : " << static_cast<int>(getSpeed());
	String str_to_return=ss.str().c_str();
	return str_to_return;


}


