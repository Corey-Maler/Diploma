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
    std::cout << "Hello, World!\n";
   
    Vector3 * as = new Vector3();
    Vector3 * bs = new Vector3();

    (*as)[0] = new Scalar(2.0);
    (*bs)[0] = new Scalar(1.2);
    
    (*as)[1] = new Scalar(4.3);
    (*bs)[1] = new Scalar(54.3);
    
    (*as)[2] = new Scalar(3.0);
    (*bs)[2] = new Scalar(5.3);
    
    Vector3 * dd = *as + *bs;
    

    
    BlockVector * gf = new BlockVector();
    
    (*gf)[0] = as;
    (*gf)[1] = bs;
    (*gf)[2] = dd;
    
    std::list<BlockVector *> * ll = integrators::Euler<BlockVector>(gf, gf);
    

    
    Vector3 * d = (*gf)[2];
    
    BlockVector * ds = ll->back();
    
    Vector3 * oo = (*ds)[2];
    
    //integrators::Steeps<Vector3>(as, bs);
    
    //std::cout << "Als " << (*oo)[2]->get() << std::endl;
    
    std::clock_t    start;
    start = std::clock();
    
    Scene * scene = new Scene();
    
    scene->Run();
    
    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    
    gnuplotio::Gnuplot gp;
    
    std::vector<std::pair<double, double> > xy_pts;
    
    for (double alpha = 0; alpha < 1; alpha += 1.0 / 24.0)
    {
        double theta = alpha*2.0*3.14159;
        xy_pts.push_back(std::make_pair(cos(theta), sin(theta)));
    }
    
    gp << "set xrange [-2:2]\nset yrange [-2:2]\n";
    gp << "plot '-' with lines title 'cubic' \n";
    gp.send1d(xy_pts);
    
    return 0;
}
