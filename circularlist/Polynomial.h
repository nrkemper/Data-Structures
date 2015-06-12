#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#pragma once

#include "CircularList.h"
#include <iostream>

typedef struct {
	int		_coefficient, _exponent;
} variable_t;

/*ostream& operator<<(ostream& os, const variable_t& v) {
	return os << "Coefficient: " << v._coefficient << endl << "Exponent: " << v._exponent << endl;
}

variable_t& operator=(variable_t& lhs, const variable_t& rhs) {
	lhs._coefficient	= rhs._coefficient;
	lhs._exponent		= rhs._exponent;
	return lhs;
}*/

class Polynomial {
	CircularList<variable_t> cll;

};

#endif