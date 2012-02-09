#ifndef HMAT_GUARD
#define HMAT_GUARD

#include <cstddef>
template <class T>
class HMat
{
public:
	typedef size_t size_type;
	//constructors
	HMat();
	HMat(const HMat&);
	HMat(const size_type, const size type, const T tmp = T());
	//destructor
	~HMat();
	//operator overloading
	HMat& operator=(const HMat&);
	HMat& operator+=(const HMat&);
	HMat& operator-=(const HMat&);
	HMat& operator*=(const HMat&);
	
	HMat inverse const();
	T det() const;
	void clear();
	void create(const size_type, const size_type)
	
	const T* const_data(size_type row = 0, size_type col = 0) const
	{
		return (data + row * c + col);
	}
	
	size_type row() const {return r;}
	size_type col() const {return c;}
private:
	size_type c, r;
	T* data;
}

#endif