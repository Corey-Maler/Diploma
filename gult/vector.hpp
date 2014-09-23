//
//  vector.hpp
//  gult
//
//  Created by Konstantin on 22/09/14.
//  Copyright (c) 2014 Konstantin. All rights reserved.
//
#ifndef VECTOR
#define VECTOR

#define EPS 0.000005

#include <stdio.h>
#include <cmath>

template< int dimension, typename T > class Vector
{
protected:
    T arr[dimension];
    
public:
    Vector()
    {
        for (int i = 0; i < dimension; i++)
        {
            arr[i] = T();
        }
    }
    
    T & operator [] (int index)
    {
        return arr[index];
    }
    
    Vector<dimension, T> * operator + (const Vector<dimension, T>& right)
    {
        Vector<dimension, T> * res = new Vector<dimension, T>();
        for (int i = 0; i < dimension; i++)
        {
            res->arr[i] = (*arr[i]) + (*right.arr[i]);
        }
        return res;
    }
    
    Vector<dimension, T> * operator * (double a)
    {
        Vector<dimension, T> * res = new Vector<dimension, T>();
        for (int i = 0; i < dimension; i++)
        {
            res->arr[i] = (*arr[i]) * a;
        }
        return res;
    }
};

template <typename T>
class Tenzor {
private:
    T val;
    
public:
    Tenzor()
    {
        //val = n;
        val = 0;
    }
    
    Tenzor(T value)
    {
        val = value;
    }
    
    T get()
    {
        return val;
    }

    T sin()
    {
        return std::sin(val);
    }
    
    T cos()
    {
        return std::cos(val);
    }
    
    void set(T value)
    {
        val = value;
    }
    
public:
    Tenzor<T> * operator + (const Tenzor<T>& right)
    {
        Tenzor<T> * res = new Tenzor<T>();
    
        res->val = val + right.val;
        
        return res;
    }
    
public:
    Tenzor<T> * operator * (double a)
    {
        Tenzor<T> * res = new Tenzor<T>();
        res->val = val * a;
        return res;
    }
};

typedef Tenzor<double> Scalar;
typedef Vector<3, Scalar *> Vector3;
typedef Vector<3, Vector3 *> BlockVector;

#endif