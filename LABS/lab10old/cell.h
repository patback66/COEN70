//
//  cell.h
//  lab10
//
//  Created by matthew alexander koken on 3/9/15.
//  Copyright (c) 2015 matthew alexander koken. All rights reserved.
//

#ifndef lab10_cell_h
#define lab10_cell_h

using namespace std;

class Cell
{
    
public:
    Cell() {
        color = 0;
    }
    //fill
    Cell *up;
    Cell *down;
    Cell *left;
    Cell *right;
    int color; //0 if untouched, 1 if visited
    Cell * parent;
    //add if necessary
    int visited() {
        return color;
    }
    void visit() {
        color = 1;
    }
};


#endif
