//
//  TrashBin.h
//  circularlist
//
//  Created by Nicholas Kemp on 2015-07-16.
//  Copyright (c) 2015 Nicholas Kemp. All rights reserved.
//

#ifndef __TRASHBIN_H__
#define __TRASHBIN_H__


#define PNTR_ARR_INC_BY     10

template <class T>
class TrashBin
{
        
private:
        static T**      _list;
        static int      _size, _num;
        
public:
        TrashBin ()
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
        
        ~TrashBin ()
        {
                int     i;
                
                for (i=0 ; i<_num ; i++)
                        delete _list[i];
                
                delete _list;
        }
};

template <class T> int TrashBin<T>::_size  = 0;
template <class T> int TrashBin<T>::_num   = 0;
template <class T> T** TrashBin<T>::_list  = (T**)0;

#endif
