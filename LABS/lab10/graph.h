//
//  graph.h
//  lab10
//
//  Created by matthew alexander koken on 3/9/15.
//  Copyright (c) 2015 matthew alexander koken. All rights reserved.
//

#ifndef lab10_graph_h
#define lab10_graph_h
#include <stack>
#include <iostream>
#include <stack>
#include "time.h"
#include "stdlib.h"
#include "cell.h"

class graph {
private:
	Cell *maze;
	int size;
	int totalSize;
public:
	graph(int r) {
		totalSize = r*r;
		size = r;
		maze = new Cell[r];
		srand(time(NULL));
		for (int i = 0; i < r; i++) {
			maze[i].setIndex(i);
		}
		initializeMaze();
	}

	~graph() {
		Cell *delMe;
		for (int i = 0; i < totalSize; i++) {
			delMe = &maze[i];
			delete delMe;
		}
		delete[] maze;
	}

	bool isIntact(int loc) {
		int intactWall = 0;
		if (maze[loc].getLeft() == NULL)
			intactWall++;
		if (maze[loc].getRight() == NULL)
			intactWall++;
		if (maze[loc].getUp() == NULL)
			intactWall++;
		if (maze[loc].getDown() == NULL)
			intactWall++;
		return (intactWall == 4) ? true : false;
	}

	void initializeMaze() {
		stack<int> CellStack;
		Cell* currentCell = &maze[0];
		int VisitedCells = 1;
		int visitOrder = 0;

		while(VisitedCells < totalSize) {
			int adjacent[4];
			int numAdjacent = 0;

			//left
			if (currentCell->getIndex()%size != 0) {
				if (isIntact(currentCell->getIndex() - 1)) {
					adjacent[numAdjacent] = currentCell->getIndex() - size;
					numAdjacent++;
				}
			}
			//right
			if (currentCell->getIndex()%size != size - 1) {
				if (isIntact(currentCell->getIndex() + 1)) {
					adjacent[numAdjacent] = currentCell->getIndex() + 1;
					numAdjacent++;
				}
			}
			//up
			if (currentCell->getIndex() - size >= 0) {
				if (isIntact(currentCell->getIndex() - size)) {
					adjacent[numAdjacent] = currentCell->getIndex() - size;
					numAdjacent++;
				}
			}
			//down
			if (currentCell->getIndex() + size < totalSize) {
				if (isIntact(currentCell->getIndex() + size)) {
					adjacent[numAdjacent] = currentCell->getIndex() + size;
					numAdjacent++;
				}
			}

			//break down walls in an intact neighbor
			if (numAdjacent > 0) {
				int neighbor = rand() % numAdjacent;
				int neighborIndex = adjacent[neighbor];

				//left
				if (neighborIndex == currentCell->getIndex() - 1) {
					currentCell->setLeft(&maze[neighborIndex]);
					maze[neighborIndex].setRight(currentCell);
				}

				//right
				else if (neighborIndex == currentCell->getIndex() + 1) {
					currentCell->setRight(&maze[neighborIndex]);
					maze[neighborIndex].setLeft(currentCell);
				}

				//up
				else if (neighborIndex == currentCell->getIndex() - size) {
					currentCell->setUp(&maze[neighborIndex]);
					maze[neighborIndex].setDown(currentCell);
				}

				//down
				else {
					currentCell->setDown(&maze[neighborIndex]);
					maze[neighborIndex].setUp(currentCell);
				}

				if (currentCell->getVisited() == -1) {
					currentCell->setVisited(visitOrder % 10); //mod by 10 because only space to print 0-9
					visitOrder++;
				}

				CellStack.push(currentCell->getIndex());
				currentCell = &maze[neighborIndex];
				VisitedCells++;
			}
			else {
				currentCell = &maze[CellStack.top()];
				CellStack.pop();
			}
		}
	}
	void solve() {
	    //iterate through starting with the end and moving up the parent until there
	    //is no parent. Each time mark color as 1 -> this is the shortest path
		printLong();
		printShortest();
	}
	void printLong() {
		for (int i = 0; i < size; i++) {
			//print top line for maze ex: + +-+-+
			for (int j = 0; j < size; j++) {
				Cell currentCell = maze[(i*size) + j];
				if (currentCell.getIndex() == 0)
					cout << "+ ";
				else if (currentCell.getUp() == NULL)
					cout << "+-";
				else
					cout << "+ ";
			}
			cout << "+\n";
			//print 2nd row for max ex: | | |
			for (int j = 0; j < size; j++) {
				Cell currentCell = maze[(i*size) + j];
				if (currentCell.getLeft() == NULL)
					cout << "| "; //print the left wall
				else
					cout << " ";
			}
			cout << "|\n"; //take care of the final wall
		}

		//print the bottom of the final row
		for (int i = 0; i < size - 1; i++) {
			cout << "+-";
		}
		cout << "+ +" << endl;
	}

	void printVisitOrder() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				Cell currentCell = maze[i*size + j];
				if (currentCell.getIndex() == 0)
					cout << "+ ";
				else if (currentCell.getUp() == NULL)
					cout << "+-";
				else
					cout << "+ ";
			}
			cout << "+\n";
			for (int j = 0; j < size; j++) {
				Cell currentCell = maze[i*size + j];
				if (currentCell.getLeft() == NULL)
					cout << "|";
				else
					cout << " ";
				if (currentCell.getVisited() != -1)
					cout << currentCell.getVisited();
				else
					cout << " ";
			}
			cout << "|\n";
		}
		//print the bottom of the final row
		for (int i = 0; i < size - 1; i++) {
			cout << "+-";
		}
		cout << "+ +" << endl;
	}

	void printShortest(){
        //pretty much the same as the other prints, except now if the 
        //cell is colored then print a # instead of a space since that will be 
        //the shortest path
        		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				Cell currentCell = maze[i*size + j];
				if (currentCell.getIndex() == 0)
					cout << "+ ";
				else if (currentCell.getUp() == NULL)
					cout << "+-";
				else
					cout << "+ ";
			}
			cout << "+\n";
			for (int j = 0; j < size; j++) {
				Cell currentCell = maze[i*size + j];
				if (currentCell.getLeft() == NULL)
					cout << "|";
				else
					cout << " ";
				if (currentCell.isColored() == 1)
					cout << "#";
				else
					cout << " ";
			}
			cout << "|\n";
		}
		//print the bottom of the final row
		for (int i = 0; i < size - 1; i++) {
			cout << "+-";
		}
		cout << "+ +" << endl;
	}
};
#endif
