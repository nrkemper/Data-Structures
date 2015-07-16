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

template <class T>
class Pointer
{
        T*      _p{};
    
public:
    
        void operator= (T* p)
        {
                if(_p)
                        delete p;
        
                _p = p;
        }
    
        ~Pointer ()
        {
                if (_p)
                        delete _p;
        }
};

#define PNTR_ARR_INC_BY     10

template <class T>
class PntrArr_t
{
        static T**      _list;
        static int      _size, _num;
    
public:
        PntrArr_t ()
        {
                _list = new T*[PNTR_ARR_INC_BY];
                _size = PNTR_ARR_INC_BY;
                _num = 0;
        }
    
        void operator+= (T*  p)
        {
                if (_num == _size)
                {
                        int     i;
                        T**     newlist = new T*[_size + PNTR_ARR_INC_BY];
                    
                        for (i=0 ; i<_size ; i++)
                            newlist[i] = _list[i];
                    
                        delete _list;
                    
                        _list = newlist;
                    
                        _size += PNTR_ARR_INC_BY;
                }
            
                _list[_num++] = p;
        }
    
        ~PntrArr_t()
        {
                int     i;
            
                for (i=0 ; i<_num ; i++)
                        delete _list[i];
            
                delete _list;
        }
};

template <class T> int PntrArr_t<T>::_size  = 0;
template <class T> int PntrArr_t<T>::_num   = 0;
template <class T> T** PntrArr_t<T>::_list  = (T**)0;

class Polynomial;

PntrArr_t<Polynomial>   pntr_arr;


class Polynomial {
	
private:
	CircularList<variable_t> cll;

	void Simplify() {
		int 	x, y, listSize;

		for( x=0, listSize=cll.GetSize() ; x < listSize; x++ ) {
			for( y=x; y < listSize; y++ ) {
				if( cll[x]._exponent == cll[y]._exponent ) {
					cll[x]._coefficient += cll[y]._coefficient;
					cll.Remove(y);
				}
			}
		}
	}

	void Sort() {
		int 		x, y, listSize;
		variable_t 	temp;

		for( x=0, listSize = cll.GetSize(); x < listSize; x++ ) {
			for( y = x; y < listSize; y++ ) {
				if( cll[x]._exponent < cll[y]._exponent) {
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

	friend istream& operator>>( istream& is, const Polynomial& pn ) {
            return is;
	}

	friend ostream& operator<<( ostream& os, const Polynomial& pn ) {
            return os;
	}

	friend Polynomial& operator+( const Polynomial& p1, 
				      const Polynomial& p2 ) {
            Polynomial* newPoly = new Polynomial;
            pntr_arr+= newPoly;
            return *newPoly;
	}
	friend Polynomial& operator-( const Polynomial& p1,
				      const Polynomial p2 ) {
            Polynomial* newPoly = new Polynomial;
            pntr_arr+= newPoly;
            return *newPoly;
	}
	
	friend Polynomial& operator*( const Polynomial& p1,
				      const Polynomial p2 ) {
            Polynomial* newPoly = new Polynomial;
            pntr_arr+= newPoly;
            return *newPoly;
	}
	
	~Polynomial() {

	}
};

Pointer<Polynomial>     glob_pointer;   //global smart pointer to be used for garbage cleanup. To be used with operators when returning references

#endif
