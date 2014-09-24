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
void Draw(std::list<T> * path, int B1, int indX, int B2, int indY)
{
    gnuplotio::Gnuplot gp;
    
    std::vector<std::pair<double, double> > xy_pts;
    
    typename std::list<T>::iterator it;
    
    for (it = path->begin(); it != path->end(); it++)
    {
        double x = (*(*it))[B1]->get(indX)->get();
        double y = (*(*it))[B2]->get(indY)->get();
        
        xy_pts.push_back(std::make_pair(x, y));
    
    }
    /*
    for (double alpha = 0; alpha < 1; alpha += 1.0 / 24.0)
    {
        double theta = alpha*2.0*3.14159;
        xy_pts.push_back(std::make_pair(cos(theta), sin(theta)));
    }
    */
    gp << "set xrange [-2:300]\nset yrange [-2:200]\n";
    gp << "plot '-' with lines title 'cubic' \n";
    gp.send1d(xy_pts);
}


template<typename T>
void Draw1D(std::list<T> * path, int B1, int indX)
{
    gnuplotio::Gnuplot gp;
    
    std::vector<std::pair<double, double> > xy_pts;
    
    int i = 0;
    
    double min = 1000000.0;
    double max = -100000.0;
    
    typename std::list<T>::iterator it;
    
    for (it = path->begin(); it != path->end(); it++)
    {
        double x = i++;
        double y = (*(*it))[B1]->get(indX)->get();
        
        if (y < min) min = y;
        if (y > max) max = y;
        
        xy_pts.push_back(std::make_pair(x, y));
        
    }
    
    gp << "set xrange [-2:" << i + 2 << "]\nset yrange [" << min << ":" << max << "]\n";
    gp << "plot '-' with lines title 'cubic' \n";
    gp.send1d(xy_pts);
}

template<typename T>
void Draw3D(std::list<T> * path, int indX, int indY, std::vector<Vector2D *> * targets)
{
    gnuplotio::Gnuplot gp;
    
    std::vector<std::pair<double, double> > xy_pts1;
    std::vector<std::pair<double, double> > xy_pts2;
    std::vector<std::pair<double, double> > xy_pts3;
    
    std::vector<std::pair<double, double> > targs(3);
    
    std::vector<Vector2D *>::iterator tt;
    
    for (tt = targets->begin(); tt != targets->end(); tt++)
    {
        double x = (*tt)->getX();
        double y = (*tt)->getY();
        targs.push_back(std::make_pair(x, y));
    }
    
    typename std::list<T>::iterator it;
    
    for (it = path->begin(); it != path->end(); it++)
    {
        double x1 = (*(*it))[0]->get(indX)->get();
        double y1 = (*(*it))[0]->get(indY)->get();
        
        xy_pts1.push_back(std::make_pair(x1, y1));
        
        double x2 = (*(*it))[1]->get(indX)->get();
        double y2 = (*(*it))[1]->get(indY)->get();
        
        xy_pts2.push_back(std::make_pair(x2, y2));
        
        double x3 = (*(*it))[2]->get(indX)->get();
        double y3 = (*(*it))[2]->get(indY)->get();
        
        xy_pts3.push_back(std::make_pair(x3, y3));
        
    }

    gp << "set xrange [-20:280]\nset yrange [-100:200]\n";
    gp << "plot '-' with lines title 'dron 1', '-' with lines title 'dron 2', '-' with lines title 'dron 3', '-' with points title 'targets' \n";
    gp.send1d(xy_pts1);
    gp.send1d(xy_pts2);
    gp.send1d(xy_pts3);
    gp.send1d(targs);
}

#endif