//
//  main.cpp
//  lab10
//
//  Created by matthew alexander koken on 3/9/15.
//  Copyright (c) 2015 matthew alexander koken. All rights reserved.
//

#include <iostream>
#include "graph.h"

int main(int argc, const char * argv[])
{

    graph *maze = new graph(10);
    maze->solve();
    return 0;
}

