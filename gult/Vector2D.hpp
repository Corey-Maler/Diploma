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
#include <cmath>

#include "vector.hpp"

class Vector2D: Vector<2, Scalar *>
{
public:
    Vector2D(double x, double y)
    {
        arr[0] = new Scalar(x);
        arr[1] = new Scalar(y);
    }
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
    
    Vector2D * inv()
    {
        return new Vector2D(-1.0 * arr[0]->get(), -1.0 * arr[1]->get());
    }
    
    Vector2D * add (Vector2D * rh)
    {
        return new Vector2D(getX() + rh->getX(), getY() + rh->getY());
    }
    
    Vector2D * extract (Vector2D * rh)
    {
        return new Vector2D(getX() - rh->getX(), getY() - rh->getY());
    }
    
    double norm ()
    {
        double x = getX();
        double y = getY();
        return sqrt(x * x + y * y);
    }
    
    double scalar(Vector2D * rh)
    {
        return (getX() * rh->getX() + getY() * rh->getY());
    }
    
    double angleTo(Vector2D * rh)
    {
        return acos(scalar(rh) / (norm() * rh->norm()));
    }
    
    double wedgeProduct(Vector2D * rh)
    {
        double a1 = getX();
        double a2 = getY();
        double b1 = rh->getX();
        double b2 = rh->getY();
        
        return a1 * b2 - a2 * b1;
    }
    
    double anticlockAngle(Vector2D * rh)
    {
        double det = wedgeProduct(rh);
        
        double sint = det / (norm() * rh->norm());
        
        return asin(sint);
    }
    
    /*
    Vector2D * operator + (Vector2D & rh)
    {
        Vector3D * res = new Vector3D(0, 0, 0);
        for (int i = 0; i < 3; i++)
        {
            res->arr[i] = (*arr[i]) * a;
        }
        return res;
    }
     */

    
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

typedef Vector<3, Vector3D *> BlockVector3d;

#endif