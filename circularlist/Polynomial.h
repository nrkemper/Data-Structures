#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#pragma once

#include "CircularList.h"
#include "TrashBin.h"
#include <iostream>

typedef struct
{
        int		_coefficient, _exponent;
} indeterminant_t;


ostream& operator<<(ostream& os, const indeterminant_t& v);

class Polynomial {
	
private:
        CircularList<indeterminant_t> cll;

public:
        Polynomial();
        void Simplify();
        void Sort();

        friend istream& operator>>( istream& is, Polynomial& pn );
        friend ostream& operator<<( ostream& os, const Polynomial& pn );
        
        friend Polynomial& operator+( const Polynomial& p1, const Polynomial& p2 );
        friend Polynomial& operator-( const Polynomial& p1,const Polynomial p2 );
        friend Polynomial& operator*( const Polynomial& p1, const Polynomial p2 );
	
        ~Polynomial();
};


extern TrashBin<Polynomial>     ply_trshbin;

istream& operator>>( istream& is, const Polynomial& pn );
ostream& operator<<( ostream& os, const Polynomial& pn );

Polynomial& operator+( const Polynomial& p1, const Polynomial& p2 );
Polynomial& operator-( const Polynomial& p1, const Polynomial p2 );
Polynomial& operator*( const Polynomial& p1, const Polynomial p2 );

#endif
