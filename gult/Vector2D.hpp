//
//  Vector2D.hpp
//  gult
//
//  Created by Konstantin on 23/09/14.
//  Copyright (c) 2014 Konstantin. All rights reserved.
//

#ifndef VECTOR2D
#define VECTOR2D

#include <stdio.h>

#include "vector.hpp"

class Vector2D: Vector<2, Scalar *>
{
public:
    double getX()
    {
        return arr[0]->get();
    }
    
    double getY()
    {
        return arr[1]->get();
    }
    
    void setX(double val)
    {
        arr[0]->set(val);
    }
    
    void setY(double val)
    {
        arr[1]->set(val);
    }
    
};

class Vector3D: public Vector3
{
public:
    Vector3D(double x, double y, double z)
    {
        arr[0] = new Scalar(x);
        arr[1] = new Scalar(y);
        arr[2] = new Scalar(z);
    }
    
    double getX()
    {
        return arr[0]->get();
    }
    
    double getY()
    {
        return arr[1]->get();
    }
    
    double getZ()
    {
        return arr[2]->get();
    }
    
    Vector3D * operator + (const Vector3D& right)
    {
        Vector3D * res = new Vector3D(0, 0, 0);
        for (int i = 0; i < 3; i++)
        {
            res->arr[i] = (*arr[i]) + (*right.arr[i]);
        }
        return res;
    }
    
    Vector3D * operator * (double a)
    {
        Vector3D * res = new Vector3D(0, 0, 0);
        for (int i = 0; i < 3; i++)
        {
            res->arr[i] = (*arr[i]) * a;
        }
        return res;
    }

};

#endif