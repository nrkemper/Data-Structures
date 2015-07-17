#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#pragma once

#include "CircularList.h"
#include "TrashBin.h"
#include <iostream>

typedef struct
{
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
	
private:
        CircularList<variable_t> cll;

        void Simplify()
        {
                int 	x, y, listSize;

                for( x=0, listSize=cll.GetSize() ; x<listSize ; x++ )
                {
                        for( y=x; y < listSize; y++ )
                        {
                                if( cll[x]._exponent == cll[y]._exponent )
                                {
                                        cll[x]._coefficient += cll[y]._coefficient;
                                        cll.Remove(y);
                                }
                        }
                }
        }

        void Sort() {
                int 		x, y, listSize;
                variable_t 	temp;

                for( x=0, listSize = cll.GetSize(); x < listSize; x++ )
                {
                        for( y = x; y < listSize; y++ )
                        {
                                if( cll[x]._exponent < cll[y]._exponent)
                                {
                                        temp = cll[y];
                                        cll[y] = cll[x];
                                        cll[x] = temp;
                                }
                        }
                }

		
	}

public:
	Polynomial() {
		cll.Append ( (variable_t){ 0, -1 } );
	}

        friend istream& operator>>( istream& is, const Polynomial& pn );

        friend ostream& operator<<( ostream& os, const Polynomial& pn );
        friend Polynomial& operator+( const Polynomial& p1, const Polynomial& p2 );
        friend Polynomial& operator-( const Polynomial& p1,const Polynomial p2 );
        friend Polynomial& operator*( const Polynomial& p1, const Polynomial p2 );
	
        ~Polynomial() {

	}
};


TrashBin<Polynomial>     trashbin;

istream& operator>>( istream& is, const Polynomial& pn )
{
        return is;
}

ostream& operator<<( ostream& os, const Polynomial& pn )
{
        return os;
}

Polynomial& operator+( const Polynomial& p1, const Polynomial& p2 )
{
        Polynomial* newPoly = new Polynomial;
        trashbin+= newPoly;
        return *newPoly;
}

Polynomial& operator-( const Polynomial& p1, const Polynomial p2 )
{
        Polynomial* newPoly = new Polynomial;
        trashbin+= newPoly;
        return *newPoly;
}

Polynomial& operator*( const Polynomial& p1, const Polynomial p2 )
{
        Polynomial* newPoly = new Polynomial;
        trashbin+= newPoly;
        return *newPoly;
}
#endif
