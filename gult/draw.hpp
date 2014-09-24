//
//  draw.hpp
//  gult
//
//  Created by Konstantin on 24/09/14.
//  Copyright (c) 2014 Konstantin. All rights reserved.
//

#ifndef CLASSDRAW
#define CLASSDRAW
#include <stdio.h>

#include <vector>
#include <list>

#include "vector.hpp"
#include "gnuplot-iostream.h"

template<typename T>
void Draw(std::list<T> * path, int indX, int indY)
{
    gnuplotio::Gnuplot gp;
    
    std::vector<std::pair<double, double> > xy_pts;
    
    typename std::list<T>::iterator it;
    
    for (it = path->begin(); it != path->end(); it++)
    {
        double x = (*(*it))[indX]->get();
        double y = (*(*it))[indY]->get();
        
        xy_pts.push_back(std::make_pair(x, y));
    
    }
    /*
    for (double alpha = 0; alpha < 1; alpha += 1.0 / 24.0)
    {
        double theta = alpha*2.0*3.14159;
        xy_pts.push_back(std::make_pair(cos(theta), sin(theta)));
    }
    */
    gp << "set xrange [-2:2]\nset yrange [-2:2]\n";
    gp << "plot '-' with lines title 'cubic' \n";
    gp.send1d(xy_pts);

}


#endif