#pragma once


#ifndef BEARPUTER_LIB_BEARMATH_H_HEADER__
#define BEARPUTER_LIB_BEARMATH_H_HEADER__

#include <functional>
#include <cmath>



#define LAS_ALL
#include "BearLAS.h"


namespace BearMath
{

	using namespace BearLas;

	typedef std::function <double(double)>  DFunction;
	typedef std::function <double(Vector&)> VFunction;

	double DerivativePoint(double in, DFunction fn);
	Vector Gradient(Vector in, VFunction fn);



}



#endif