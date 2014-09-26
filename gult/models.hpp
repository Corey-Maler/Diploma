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

#define PI 3.14159265359

class models
{
    
};

class drone
{
private:
    Vector2D * target;
    Vector3D * position;
    
    double VMax; // Max velocity
    double OMax; // Max angular velocity
    double r; // Rotation radius
    
public:
    /**
     * Описашка класса
     */
    drone(double vmax, double omax)
    {
        VMax = vmax;
        OMax = omax;
        r = vmax / omax;
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
    
    double AngleToTarget(Vector2D * targ)
    {
        double x = target->getX() - (*position)[0]->get();
        double y = target->getY() - (*position)[1]->get();
        double a = atan2(y, x) - position->getZ();
        if (a > PI) a -= 2 * PI;
        if (a < -PI) a += 2 * PI;
        return a;
    }
    
    double PathToTarget(Vector2D * targ)
    {
        bool isLeft = false;
        double ang = AngleToTarget(targ);
        if (ang > 0) isLeft = true; // else false
        
        double theta;
        
        if (isLeft)
        {
            theta = position->getZ() + PI / 2.0;
        }
        else
        {
            theta = position->getZ() - PI / 2.0;
        }
        
        Vector2D * P = new Vector2D(position->getX(), position->getY());
        Vector2D * n = new Vector2D(r * cos(theta), r * sin(theta));
        
                    // R = targ - (P + n)
        Vector2D * G = P->add(n);
        Vector2D * R = targ->extract(G);
        Vector2D * ni = n->inv();
        
        double beta = R->angleTo(n->inv());
        double beta1 = ni->anticlockAngle(R);
        if (!isLeft) beta1 *= -1;
        double e = acos(r / R->norm());
        
        if (beta1 < 0)
            beta = 2 * PI - beta;
        
        /*
        if (beta1 > 0 && !isLeft)
            beta = 2 * PI - beta;
        */
         
        double eps = beta - e;
        double L = r * eps;
        
        double Rn = R->norm();
        double T = sqrt(Rn * Rn + r * r);
        return L + T;
    }
    
    double AngleToTarget()
    {
        return AngleToTarget(target);
    }
    
    Vector3D * rightPart(Vector3D * X)
    {
        Vector3D * Y = new Vector3D(0, 0, 0);
        
        double omega = 0;
        double ang = AngleToTarget();
        if (ang > EPS) omega = OMax;
        if (ang < -EPS) omega = -OMax;
        
        //omega = 0;
        
        (*Y)[0] = new Scalar(VMax * (*X)[2]->cos());
        (*Y)[1] = new Scalar(VMax * (*X)[2]->sin());
        (*Y)[2] = new Scalar(omega);
        
        double gamma = (*X)[2]->get();
        while (gamma > 2 * PI)
        {
            gamma -= 2 * PI;
            (*X)[2]->set(gamma);
        }
        
        while (gamma < 0)
        {
            gamma += 2 * PI;
            (*X)[2]->set(gamma);
        }
        
        position = X;
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