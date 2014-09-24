//
//  integrators.hpp
//  gult
//
//  Created by Konstantin on 22/09/14.
//  Copyright (c) 2014 Konstantin. All rights reserved.
//
#ifndef INTEGRATORS
#define INTEGRATORS
#include <stdio.h>
#include <iostream>
#include "vector.hpp"
#include "scene.hpp"
#include <list>

namespace integrators {
    
    template <typename V>
    std::list<V *> * Euler(Scene *scene, double t0, double dt, double te)
    {
        std::list<V *> * path = new std::list<V *>();
        
        V* X = scene->getX0();
        
        for (double t = t0; t < te; t += dt)
        {
            X = (*X) + *((*(scene->F(X))) * dt);
            path->push_back(X);
        }
        
        return path;
    }
    
    template <typename V>
    void Steeps(V* (*fx)(V *), V * x0, double dt)
    {
        V* X = x0;
        bool go = true;
        while (go)
        {
            //std::cout << (*y)[0]->get() << std::endl;
            
            X = (*X) + *((*(fx(X))) * dt);
            
            char a;
            std::cin >> a;
            switch (a) {
                case 'e':
                    
                    break;
                default:
                    go = false;
                    break;
            }
        }
    }
}

#endif