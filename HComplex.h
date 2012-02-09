#ifndef HCOMPLEX_GUARD
#define HCOMPLEX_GUARD
#include <stdexcept>
#include <iostream>

template <class T>
class HComplex
{
public:
	T re, im;
	
	HComplex() : re(0), im(0) {;}
	HComplex(const T &i, const T &j) : re(i), im(j) {;}
	HComplex(const T &i) : re(i), im(0){;}
	
	HComplex& operator=(const HComplex& h) {re = T(h.re); im = T(h.im); return *this;}
	HComplex& operator+=(const HComplex& h) {re += h.re; im += h.im; return *this;}
	HComplex operator-() const {HComplex tmp; tmp.re = -re; tmp.im = -im; return tmp;}
	HComplex& operator-=(const HComplex& h)
	{
		HComplex& tmp = *this;
		tmp += (-h); return tmp;
	}
	HComplex& operator*=(const HComplex &h)
	{
		T tmpr = re * h.re - im * h.im;
		im = re * h.im + im * h.re;
		re = tmpr;
		return *this;
	}
	HComplex operator~() const {return HComplex(re, -im);}
	HComplex& operator/=(const HComplex& h)
	{
		if (!(h.re || h.im))
		{
			throw(std::domain_error("·¢Éú³ý0´íÎó!!"));
		}
		else
		{
			HComplex tmp = h.re * h.re + h.im * h.im;
			(*this) *= ~h;
			re /= tmp;
			im /= tmp;
			return (*this);
		}
	}
	
	operator T() {return re;}
};

template <class T>
inline HComplex<T> operator+(const HComplex<T>& lhs, const HComplex<T>& rhs)
{
	HComplex<T> tmp = lhs;
	tmp += rhs;
	return tmp;
}

template <class T>
inline HComplex<T> operator*(const HComplex<T>& lhs, const HComplex<T>& rhs)
{
	HComplex<T> tmp = lhs;
	tmp *= rhs;
	return tmp;
}

template <class T>
inline HComplex<T> operator-(const HComplex<T>& lhs, const HComplex<T>& rhs)
{
	HComplex<T> tmp = lhs;
	tmp -= rhs;
	return tmp;
}

template <class T> 
inline std::ostream& operator<<(std::ostream& co, HComplex<T> com)
{
	if (com.im >= 0)
		co << com.re << '+' << com.im;
	else
		co << com.re << '-' << (-com.im);
	co << 'i';
	return co;
}

template <class T> 
inline bool operator==(HComplex<T> lhs, HComplex<T> rhs)
{
	return (lhs.re == rhs.re && lhs.im == rhs.im);
}

template <class T> 
inline bool operator!=(HComplex<T> lhs, HComplex<T> rhs)
{
	return !(lhs.re == rhs.re && lhs.im == rhs.im);
}

#endif
