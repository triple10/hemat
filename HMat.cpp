#include "HMat.h"
#include <iostream>

HMat::HMat()
{
	c = r = T();
	data = 0;
}

HMat::HMat(const HMat& h)
{
	data = (T*)(malloc((r = h.row()) * (c = h.col()) * sizeof(T)));
	for ((size_type i = 0, T *tmp = data, const T* tmp1 = h.const_data(),
			size_type sz = c * r); i != sz; i++)
	{
		*tmp++ = *tmp1++;
	}
}

HMat::HMat(const size_type co, const size_type ro, const T tmp = T())
{
	data = (T*)(malloc((r = ro) * (c = co) * sizeof(T)));
	for ((size_type i = 0, T *tmp = data, size_type sz = c * r); i != sz; i++)
	{
		*tmp++ = tmp;
	}
}