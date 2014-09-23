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


#endif