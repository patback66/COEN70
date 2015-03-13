//
//  cell.h
//  lab10
//
//  Created by matthew alexander koken on 3/9/15.
//  Copyright (c) 2015 matthew alexander koken. All rights reserved.
//

#ifndef CELL_H
#define CELL_H
#include <iostream>
using namespace std;

class Cell {
public:
	Cell()
	{
		up = NULL;
		down = NULL;
		left = NULL;
		right = NULL;
		parent = NULL;
		index = 0;
		visited = -1;
		color = 0;
	}
	//Accssors
	Cell* getUp() {
		return up;
	}
	Cell* getDown() {
		return down;
	}
	Cell* getLeft() {
		return left;
	}
	Cell* getRight() {
		return right;
	}
	Cell* getParent() {
		return parent;
	}
	int getIndex() {
		return index;
	}
	int getVisited() {
		return visited;
	}
	int getColor() {
		return color;
	}

	//Mutators
	void setUp(Cell* c) {
		up = c;
	}
	void setDown(Cell* c) {
		down = c;
	}
	void setLeft(Cell* c) {
		left = c;
	}
	void setRight(Cell* c) {
		right = c;
	}
	void setParent(Cell*c) {
		parent = c;
	}
	void setIndex(int i) {
		index = i;
	}
	void setVisited(int v) {
		visited = v;
	}
	void setColor(int c) {
		color = c;
	}
private:
	Cell* up;
	Cell* down;
	Cell* left;
	Cell* right;
	Cell* parent;
	int visited;
	int index;
	int color;
};


#endif