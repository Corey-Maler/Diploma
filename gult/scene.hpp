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
#include <list>

#include "vector.hpp"
#include "Vector2D.hpp"
#include "integrators.hpp"
#include "models.hpp"
#include "draw.hpp"

class Scene
{
private:
    drone * Drone;
    
public:
    
    static BlockVector3d * F (BlockVector3d * X)
    {
        std::cout << "Steep. X: " << (*X)[0]->getX() << ", Y: " << (*X)[0]->getY() << ", Z: " << (*X)[0]->getZ() << std::endl;
        Vector3D * Y = new Vector3D(1.0, 1.0, 1.0);
        
        BlockVector3d * V = new BlockVector3d();
        (*V)[0] = Y;
        (*V)[1] = Y;
        (*V)[2] = Y;
        return V;
    }
    
    void Run()
    {
        Drone = new drone(10, 10);
        std::cout << "RUN scene" <<std::endl;
        
        BlockVector3d* (*fx)(BlockVector3d *);
        
        fx = F;
        
        Vector3D * as = new Vector3D(0, 0, 0);
        Vector3D * bs = new Vector3D(0, 0, 0);
        Vector3D * cs = new Vector3D(0, 0, 0);
        BlockVector3d * x0 = new BlockVector3d();
        (*x0)[0] = as;
        (*x0)[1] = bs;
        (*x0)[2] = cs;
        

        std::list<BlockVector3d *> * path = integrators::Euler<BlockVector3d>(fx, x0, 0, 0.1, 10);
        
        Draw<BlockVector3d *>(path, 0, 0, 0, 1);
        
    }
};

#endif