//
//  scene.hpp
//  gult
//
//  Created by Konstantin on 23/09/14.
//  Copyright (c) 2014 Konstantin. All rights reserved.
//

#ifndef SCENE
#define SCENE

#include <stdio.h>
#include <iostream>

#include "vector.hpp"
#include "Vector2D.hpp"
#include "integrators.hpp"
#include "models.hpp"

class Scene
{
public:
    
    static Vector3D * F (Vector3D * X)
    {
        std::cout << "Steep. X: " << X->getX() << ", Y: " << X->getY() << ", Z: " << X->getZ() << std::endl;
        Vector3D * Y = new Vector3D(1.0, 1.0, 1.0);
        return Y;
    }
    
    void Run()
    {
        std::cout << "RUN scene" <<std::endl;
        
        Vector3D* (*fx)(Vector3D *);
        
        fx = F;
        
        Vector3D * as = new Vector3D(0, 0, 0);

        integrators::Steeps<Vector3D>(fx, as, 0.1);
    }
};

#endif