#include "my_time.h" // header in local directory

using namespace std;


Time::Time(unsigned long int hours,unsigned char minutes,unsigned char seconds=0):hours(hours),minutes(minutes),seconds(seconds)
{	
		if(hours>maxHours || hours <minValue || minutes > maxMS || minutes< minValue || seconds > maxMS || seconds< minValue){
			throw invalid_argumen();
		}
}

void Time::cal(unsigned long seconds){
Time::hours=static_cast<short unsigned int>(seconds/3600);
Time::minutes=static_cast<unsigned char>(seconds%3600)/60;
Time::seconds=static_cast<unsigned char>((seconds%3600)%60);
}

Time::Time(unsigned long seconds){
cal(seconds);
}

std::string Time::get_as_string(bool is_using_days)const 
{
	char buffer[10];

	if (is_using_days)
	{
  		sprintf (buffer, "%ld:%d:%d", Time::hours, Time::minutes, Time::seconds);
		return buffer;
	}
	else
	{
		unsigned short d = static_cast<short unsigned int>(Time::hours / 24);
		sprintf (buffer, "%d. %ld:%d:%d", d, Time::hours % 24, Time::minutes, Time::seconds);

		return buffer;
	}
}


unsigned long int Time::get_seconds(){
	unsigned long int totalSec=Time::seconds;
	totalSec+=Time::minutes*60;
	totalSec+=Time::hours*3600;
	return totalSec;
}


void print(const Time t){
printf("%s\n",t.get_as_string(true).c_str());
}


Time Time::operator +(Time t2){
Time result(Time::get_seconds()+t2.get_seconds());
return result;

}


Time Time::operator +(unsigned long seconds){
Time result(seconds+Time::get_seconds());

return result;
}

void Time::operator +=(unsigned long seconds){
Time::cal(seconds+Time::get_seconds());
}


bool Time::operator ==(Time t2){
	if(Time::get_seconds()==t2.get_seconds())
		return true;
	else
		return false;
}

bool Time::operator <=(Time t2){
	if(Time::get_seconds()<=t2.get_seconds())
		return true;
	else
		return false;
}

bool Time::operator >=(Time t2){
	if(Time::get_seconds()<=t2.get_seconds())
		return true;
	else
		return false;
}

bool Time::operator !=(Time t2){
	if(Time::get_seconds()!=t2.get_seconds())
		return true;
	else
		return false;
}
bool Time::operator <(Time t2){
	if(Time::get_seconds()<t2.get_seconds())
		return true;
	else
		return false;
}
bool Time::operator >(Time t2){
	if(Time::get_seconds()>t2.get_seconds())
		return true;
	else
		return false;
}

std::ostream & operator <<(std::ostream &out, const Time &t){
out << t.get_as_string(false) <<"\n";
return out;
}













