//
//  Polynomial.cpp
//  CircularList
//
//  Created by Nicholas Kemp on 2015-07-17.
//  Copyright (c) 2015 Nicholas Kemp. All rights reserved.
//



#include "Polynomial.h"
#include "TrashBin.h"
#include <iostream>


TrashBin<Polynomial>     ply_trshbin;

ostream& operator<<(ostream& os, const indeterminant_t& v) {
        return os << "Coefficient:\t" << v._coefficient << endl << "Exponent:\t\t" << v._exponent << endl << endl;
 }


Polynomial :: Polynomial() {
        cll.Append ( (indeterminant_t){ 0, -1 } );
}

void Polynomial :: Simplify ()
{
        int 	x, y, listSize;
                
        for (x=0, listSize=cll.GetSize() ; x<listSize ; x++)
        {
                y = 0;
                while (y<listSize)
                {
                        if (cll[x]._exponent == cll[y]._exponent && y != x)
                        {
                                cll[x]._coefficient += cll[y]._coefficient;
                                cll.Remove(y);
                                
                                listSize--;
                        }
                        else
                        {
                                y++;
                        }
                }
        }
}
        
void Polynomial :: Sort()
{
        int                     x, y, listSize;
        indeterminant_t         temp;
                
        for( x=0, listSize = cll.GetSize(); x < listSize; x++ )
        {
                for( y = x; y < listSize; y++ )
                {
                        if( cll[x]._exponent > cll[y]._exponent)
                        {
                                temp = cll[y];
                                cll[y] = cll[x];
                                cll[x] = temp;
                        }
                }
        }
}
        

Polynomial :: ~Polynomial() {
                
}

istream& operator>>( istream& is, Polynomial& pn )
{
        char            input[1000], newnum_s[100];
        char            *input_pntr, *newnum_beg, *newnum_pntr;
        int             isCoeff = 1;
        
        indeterminant_t indet;
        
        is.getline (input, 1000);
        
        input_pntr = input;
        newnum_pntr = newnum_beg = newnum_s;
        
        
        do
        {
                if (*input_pntr != ' ' && *input_pntr != '\n' && *input_pntr != '\0')
                        *newnum_pntr++ = *input_pntr;
                else
                {
                        *newnum_pntr = '\0';
                        
                        if (isCoeff)
                        {
                                indet._coefficient = atoi (newnum_s);
                                isCoeff = 0;
                        }
                        else
                        {
                                indet._exponent = atoi (newnum_s);
                                pn.cll.Push(indet);
                                isCoeff = 1;
                        }
                        
                        newnum_pntr = newnum_beg;
                }
        } while (*input_pntr++);
        return is;
}

ostream& operator<<( ostream& os, const Polynomial& pn )
{
        pn.cll.Print();
        return os;
}

Polynomial& operator+( const Polynomial& p1, const Polynomial& p2 )
{
        Polynomial* newPoly = new Polynomial;
        ply_trshbin+= newPoly;
        return *newPoly;
}

Polynomial& operator-( const Polynomial& p1, const Polynomial p2 )
{
        Polynomial* newPoly = new Polynomial;
        ply_trshbin+= newPoly;
        return *newPoly;
}

Polynomial& operator*( const Polynomial& p1, const Polynomial p2 )
{
        Polynomial* newPoly = new Polynomial;
        ply_trshbin+= newPoly;
        return *newPoly;
}
