#ifndef __TIME_H__
#define __TIME_H__

#include<time.h>

class Time {
	public:
		Time(unsigned int time);
		~Time();
		void now();
		Time operator+(Time const & other);
		Time operator+=(unsigned int & other);
		time_t get_time() const;
	private:
		time_t m_time;
		unsigned int u_time;
};

bool operator<=(Time const & first,Time const & other);

bool operator>=(Time const & first,Time const & other);

bool operator<(Time const & first,Time const & other);

bool operator>(Time const & first,Time const & other);

/*********************inline*****************************/

inline Time::Time(unsigned int time)
{
	now();
	m_time += time;
	u_time = time;
}

inline Time::~Time(){}

inline void Time::now()
{
	m_time = time(NULL);
}
inline Time Time::operator+=(unsigned int & other)
{
	m_time+=other;
	return *this;
}
inline Time Time::operator+(Time const & other)
{
	Time result(u_time + other.u_time );
	return result;
}

inline time_t Time::get_time() const
{
	return m_time;
}

inline bool operator<=(Time const & first,Time const & other)
{
	return (first.get_time() <= other.get_time());
}

inline bool operator>=(Time const & first,Time const & other)
{
	return (first.get_time() >= other.get_time());
}

inline bool operator<(Time const & first,Time const & other)
{
	return (first.get_time() < other.get_time());
}

inline bool operator>(Time const & first,Time const & other)
{
	return (first.get_time() > other.get_time());
}




#endif /* __TIME_H__ */
