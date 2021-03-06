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
#include <vector>
#include <iostream>
#include <stack>
#include "time.h"
#include "stdlib.h"
#include "cell.h"
#include <algorithm>

class graph {
private:
	Cell *maze;
	int size;
	int totalSize;
public:
	//Constructor
	graph(int r) {
		totalSize = r*r;
		size = r;
		maze = new Cell[totalSize];
		srand(time(NULL));
		for (int i = 0; i < r*r; i++) {
			maze[i].setIndex(i);
		}
		initializeMaze();
	}
	//Destructor
	~graph() {
		Cell *delMe;
		for (int i = 0; i < totalSize; i++) {
			delMe = &maze[i];
			delete delMe;
		}
		delete[] maze;
	}

	//True if all 4 walls are intact, else false
	bool isIntact(int loc) {
		int intactWall = 0;
		if (maze[loc].getLeft() == NULL)
			intactWall++;
		if (maze[loc].getRight() == NULL)
			intactWall++;
		if (maze[loc].getUp()== NULL)
			intactWall++;
		if (maze[loc].getDown() == NULL)
			intactWall++;
		return (intactWall == 4) ? true : false;
	}

	//DFS to build the maze
	void initializeMaze() {
		bool exit_reached = false;
		stack<int> CellStack;
		Cell* currentCell = &maze[0];
		int VisitedCells = 1;
		int visitOrder = 0;
		currentCell->setVisited(visitOrder);
		while(VisitedCells < totalSize) {
			int adjacent[4]; //add the indexes of the adjacent columns to this list
			int numAdjacent = 0;
			//If we're not in the first column, go left
			if (currentCell->getIndex()%size != 0) {
				//Is left's walls totally intact?
				if (isIntact(currentCell->getIndex() - 1)) {
					//Insert the left element as one of the adjacents
					adjacent[numAdjacent] = currentCell->getIndex() - 1;
					numAdjacent++;
				}
			}
			//If we're not in the last column, go right
			if (currentCell->getIndex()%size != size - 1) {
				if (isIntact(currentCell->getIndex() + 1)) {
					adjacent[numAdjacent] = currentCell->getIndex() + 1;
					numAdjacent++;
				}
			}
			//If we're not in the first row, go up
			if (currentCell->getIndex() - size >= 0) {
				if (isIntact(currentCell->getIndex() - size)) {
					adjacent[numAdjacent] = currentCell->getIndex() - size;
					numAdjacent++;
				}
			}
			//If we're not in the last column, go down
			if (currentCell->getIndex() + size < totalSize) {
				if (isIntact(currentCell->getIndex() + size)) {
					adjacent[numAdjacent] = currentCell->getIndex() + size;
					numAdjacent++;
				}
			}
			/*We now hove all the adjacent cells with walls still intact*/
			//break down wall to one of them
			if (numAdjacent > 0) {
				int neighbor = rand() % numAdjacent;
				int neighborIndex = adjacent[neighbor];

				//left is picked and wall is broken down, i.e. they reference to each other
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
				/*First visit? */
				if (maze[neighborIndex].getVisited() == -1 && !exit_reached) {
					visitOrder++;
					maze[neighborIndex].setVisited(visitOrder % 10);
					// currentCell->setVisited(visitOrder % 10); //mod by 10 because only space to print 0-9
				}
				if (neighborIndex == size*size -1){
					exit_reached = true;
				}
				/*Put Cell on stack and proceed to process neighbor*/
				CellStack.push(currentCell->getIndex());
				maze[neighborIndex].setParent(currentCell);
				currentCell = &maze[neighborIndex];
				VisitedCells++;
			}
			/*If there's no way 'forward' we backtrack to the 'parent' cell */
			else{
				if (currentCell->getVisited() == -1 && !exit_reached) {
					currentCell->setVisited(visitOrder % 10); //mod by 10 because only space to print 0-9
					visitOrder++;
				}
				//back up to the cell on top of the stack
				currentCell = &maze[CellStack.top()];
				CellStack.pop();
			}
		}
	}
	void solve() {
		cout << "Empty Maze: " << endl;
		printLong();
		cout << endl << "VisitOrder path: " <<endl;
		printVisitOrder();
		cout << endl << "Shortest path: " <<endl;
		printShortest();
		cout << endl;
	}
	void printLong() {
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
				cout << " ";
			}
			/*End of the row and therefore the line*/
			cout << "|\n";
		}
		//print the bottom of the final row
		for (int i = 0; i < size - 1; i++) {
			cout << "+-";
		}
		cout << "+ +" << endl;
	}

	void printVisitOrder() {
		for (int i = 0; i < size; i++) {
			//print the top of the cells
			for (int j = 0; j < size; j++) {
				Cell currentCell = maze[i*size + j];
				if (currentCell.getIndex() == 0)
					cout << "+ ";
				else if (currentCell.getUp() == NULL)
					cout << "+-";
				else
					cout << "+ ";
			}
			//for the last cell
			cout << "+\n";
			for (int j = 0; j < size; j++) {
				Cell currentCell = maze[i*size + j];
				if (currentCell.getLeft() == NULL)
					cout << "|";
				else
					cout << " ";
				/*Have the algoritm visited the node? If so in what order?*/
				if (currentCell.getVisited() != -1)
					cout << currentCell.getVisited();
				else
					cout << " ";
			}
			/*End of the row and therefore the line*/
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
        vector<int> shortest_path;

        int index = totalSize-1;
        int i = 0;
        Cell* currentCell = &maze[index];
        while(index != 0){
        	index = currentCell->getIndex();
        	shortest_path.push_back(index);
        	currentCell = currentCell->getParent();
   		}
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
				if ((find(shortest_path.begin(), shortest_path.end(), currentCell.getIndex()) != shortest_path.end()))
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
