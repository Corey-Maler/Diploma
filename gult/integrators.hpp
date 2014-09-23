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
#include <list>

namespace integrators {
    
    template <typename V>
    std::list<V *> * Euler(V * x0, V * y)
    {
        std::list<V *> * path = new std::list<V *>();
        
        for (int i = 0; i < 10; i++)
        {
            path->push_back((*x0) + *((*y) * i));
        }
        
        return path;
    }
    
    template <typename V>
    void Steeps(V * x0, V * y)
    {
        bool go = true;
        while (go)
        {
            //std::cout << (*y)[0]->get() << std::endl;
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