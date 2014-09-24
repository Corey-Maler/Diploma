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
#include <vector>

#include "vector.hpp"
#include "Vector2D.hpp"
#include "integrators.hpp"
#include "models.hpp"
#include "draw.hpp"

class Scene
{
private:
    drone * Drone1;
    drone * Drone2;
    drone * Drone3;
    
    Vector2D * t1;
    Vector2D * t2;
    Vector2D * t3;
    
public:
    
    Scene()
    {
        double oMax = 0.2;
        double vMax = 3;
        Drone1 = new drone(vMax, oMax);
        Drone2 = new drone(vMax, oMax);
        Drone3 = new drone(vMax, oMax);
        
        Drone1->setPosition(new Vector3D(10.0, 10.0, 0.2));
        Drone2->setPosition(new Vector3D(100.0, 10.0, 0.1));
        Drone3->setPosition(new Vector3D(200.0, 10.0, -0.3));
        
        t1 = new Vector2D(30.0, 100.0);
        t2 = new Vector2D(90.0, 100.0);
        t3 = new Vector2D(210.0, 100.0);
        
        Drone1->setTarget(t1);
        Drone2->setTarget(t2);
        Drone3->setTarget(t3);
        
    }
    
    std::vector<Vector2D *> * getTargets()
    {
        std::vector<Vector2D * > * res = new std::vector<Vector2D * > ();
        
        res->push_back(t1);
        res->push_back(t2);
        res->push_back(t3);
        
        return res;
    }
    
    BlockVector3d * F (BlockVector3d * X)
    {
        BlockVector3d * V = new BlockVector3d();
        (*V)[0] = Drone1->rightPart((*X)[0]);
        (*V)[1] = Drone2->rightPart((*X)[1]);
        (*V)[2] = Drone3->rightPart((*X)[2]);
        return V;
    }
    
    BlockVector3d * getX0()
    {
        //Vector3D * as = new Vector3D(0, 0, 0);
        //Vector3D * bs = new Vector3D(0, 0, 0);
        //Vector3D * cs = new Vector3D(0, 0, 0);
        BlockVector3d * x0 = new BlockVector3d();
        (*x0)[0] = Drone1->getPosition();
        (*x0)[1] = Drone2->getPosition();
        (*x0)[2] = Drone3->getPosition();
        return x0;
    }
    
    void Run()
    {
        //Drone = new drone(10, 10);
        std::cout << "RUN scene" <<std::endl;
    }
};

#endif