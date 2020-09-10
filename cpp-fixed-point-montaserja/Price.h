#ifndef __PRICE_H__
#define __PRICE_H__

#include<iostream>

class Price
{
	public:
		Price(int dollar=0,unsigned char cent=0);
		int getDollar() const;
		unsigned char getCent() const;
		
		
		Price& operator+=(const Price& p);
		Price& operator-=(const Price& p);
		Price& operator*=(const Price& p);
		Price& operator/=(const Price& p);
		Price& operator%=(const Price& p);
		operator double() const;
		// Define prefix increment operator.
		Price& operator++();

		// Define postfix increment operator.
		Price operator++(int);
		
		// Define prefix decrement operator.
		Price& operator--();

		// Define postfix decrement operator.
		Price operator--(int);
		Price& operator=(int);
		
		friend std::ostream& operator<<(std::ostream& os,const Price&);
		
		
	
	private:
		int m_dollar;
		unsigned char m_cent;


};

Price operator+(const Price& p1,const Price&  p2);
Price operator-(const Price& p1,const Price&  p2);
Price operator*(const Price& p1,const Price&  p2);
Price operator/(const Price& p1,const Price&  p2);
Price operator%(const Price& p1,const Price&  p2);

bool operator==(const Price& p1,const Price&  p2);
bool operator!=(const Price& p1,const Price&  p2);
bool operator>(const Price& p1,const Price&  p2);
bool operator<(const Price& p1,const Price&  p2);
bool operator>=(const Price& p1,const Price&  p2);
bool operator<=(const Price& p1,const Price&  p2);

unsigned char get_cent_from_double(double);

inline Price::operator double() const{
	double temp =getDollar();
	temp+=double(getCent())/100;
	return temp;

}

inline Price::Price(int dollar,unsigned char cent):m_dollar(dollar),m_cent(cent){}

inline int Price::getDollar() const
{
	return m_dollar;
}
inline unsigned char Price::getCent() const
{
	return m_cent;
}


inline bool operator==(const Price& p1,const Price&  p2)
{
	if(p1.getDollar()== p2.getDollar() &&  p1.getCent() == p2.getCent())
		return true;
	return false;
}

inline bool operator!=(const Price& p1,const Price&  p2)
{
	return !(p1==p2);
}

inline bool operator>(const Price& p1,const Price&  p2)
{
	if(p1.getDollar()> p2.getDollar() || (p1.getDollar() == p2.getDollar() &&  p1.getCent() > p2.getCent()))
		return true;
	return false;
}
inline bool operator<(const Price& p1,const Price&  p2)
{
	if(p1!=p2 && !(p1>p2))
		return true;
	return false;
}
inline bool operator>=(const Price& p1,const Price&  p2)
{
	if(p1==p2 || !(p1>p2))
		return true;
	return false;
}
inline bool operator<=(const Price& p1,const Price&  p2)
{
	if(p1==p2 || !(p1<p2))
		return true;
	return false;
}

inline unsigned char get_cent_from_double(double temp)
{
	return char((temp-int(temp))*100);
}

inline Price operator*(const Price& p1,const Price&  p2)
{
	double temp =double(p1)*double(p2);
	return Price(int(temp),get_cent_from_double(temp));
}

inline Price operator/(const Price& p1,const Price&  p2)
{
	double temp =double(p1)/double(p2);
	return Price(int(temp),get_cent_from_double(temp));
}

inline Price operator%(const Price& p1,const Price&  p2)
{
	int p1_temp=int(double(p1) * 100);
	int p2_temp=int(double(p2) * 100);
	
	int sharet = p1_temp % p2_temp;
	
	double temp = sharet;
	temp/=100;
	return Price(int(temp),get_cent_from_double(temp));
}


inline Price operator+(const Price& p1,const Price&  p2)
{
	double temp =double(p1)+double(p2);
	return Price(int(temp),get_cent_from_double(temp));
}


inline Price operator-(const Price& p1,const Price&  p2)
{
	double temp =double(p1)-double(p2);
	return Price(int(temp),get_cent_from_double(temp));
}


inline Price& Price::operator+=(const Price& p)
{
	*this = *this + p;
	return *this;
}

inline Price& Price::operator-=(const Price& p)
{
	*this = *this - p;
	return *this;
}

inline Price& Price::operator*=(const Price& p)
{
	*this = *this * p;
	return *this;
}
inline Price& Price::operator/=(const Price& p)
{
	*this = *this / p;
	return *this;
}
inline Price& Price::operator%=(const Price& p)
{
	*this = *this % p;
	return *this;
}


// Define prefix increment operator.
inline Price& Price::operator++()
{
   m_dollar++;
   return *this;
}

// Define postfix increment operator.
inline Price Price::operator++(int)
{
   Price temp = *this;
   ++*this;
   return temp;
}

// Define prefix decrement operator.
inline Price& Price::operator--()
{
   m_dollar--;
   return *this;
}

// Define postfix decrement operator.
inline Price Price::operator--(int)
{
   Price temp = *this;
   --*this;
   return temp;
}

inline Price& Price::operator=(int x)
{
	m_dollar = x;
	m_cent=0;
	return *this;
}

inline std::ostream& operator<<(std::ostream& os,const Price& p)
{
	os << p.getDollar() << "." << int(p.getCent());
	return os;
}















#endif /* __PRICE_H__ */
