//
//  main.cpp
//  gult
//
//  Created by Konstantin on 22/09/14.
//  Copyright (c) 2014 Konstantin. All rights reserved.
//
#include <ctime>
#include <iostream>
#include <vector>
#include <list>

#include "vector.hpp"
#include "integrators.hpp"
#include "Vector2D.hpp"
#include "models.hpp"
#include "scene.hpp"
#include "draw.hpp"

#include "gnuplot-iostream.h"

int fx(int x, int y)
{
    return x * (y - 1);
}

Vector3 v;

int main(int argc, const char * argv[]) {
    std::cout << "Running integration...\n";
    
    std::clock_t start;
    start = std::clock();
    
    Scene * scene = new Scene();
    
    scene->Run();
    
    std::list<BlockVector3d *> * path = integrators::Euler<BlockVector3d>(scene, 0, 0.1, 10);
    
    Draw3D<BlockVector3d *>(path, 0, 1, scene->getTargets());
    
    std::cout << "End of integration\n";
    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    return 0;
}
