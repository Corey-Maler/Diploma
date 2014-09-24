//
//  models.hpp
//  gult
//
//  Created by Konstantin on 23/09/14.
//  Copyright (c) 2014 Konstantin. All rights reserved.
//

#ifndef MODELS
#define MODELS

#include <stdio.h>
#include <string>
#include <sstream>
#include <cmath>

#include "Vector2D.hpp"

class models
{
    
};

class drone
{
private:
    Vector2D * target;
    Vector3D * position;
    
    double VMax;
    double OMax;
    
public:
    /**
     * Описашка класса
     */
    drone(double vmax, double omax)
    {
        VMax = vmax;
        OMax = omax;
    }
    
    void setTarget(Vector2D * targ)
    {
        target = targ;
    }
    
    void setPosition(Vector3D * pos)
    {
        position = pos;
    }
    
    Vector3D * getPosition()
    {
        return position;
    }
    
    double AngleToTarget()
    {
        double x = target->getX() - (*position)[0]->get();
        double y = target->getY() - (*position)[1]->get();
        
        return atan2(y, x);
        //return 0;
    }
    
    Vector3D * rightPart(Vector3D * X)
    {
        Vector3D * Y = new Vector3D(0, 0, 0);
        
        double omega = 0;
        double ang = AngleToTarget();
        if (ang > EPS) omega = OMax;
        if (ang < -EPS) omega = -OMax;
        
        (*Y)[0] = new Scalar(VMax * (*X)[2]->sin());
        (*Y)[1] = new Scalar(VMax * (*X)[2]->cos());
        (*Y)[2] = new Scalar(omega);
        
        position = Y;
        return Y;
    }
    
    double PathTo(Vector2D * tar)
    {
        double ang = AngleToTarget();
        
        //if (
        
        return 0;
    }
    
    std::string toString()
    {
        std::stringstream ss;
        ss << 233;
        
        return ss.str();
        
    }
};

#endif