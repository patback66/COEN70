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
#include "time.h"
#include "stdlib.h"
#include "cell.h"

class graph {
private:
    Cell ** maze;
    int length, width;
public:
    graph(int cols, int rows) {
        maze = new Cell*[cols];
        for(int i = 0; i < cols; i++)
            maze[i] = new Cell[rows];
        length = rows;
        width = cols;
        srand(time(NULL));
        initializeMaze();
    }
    
    void clear() {
        for(int i = 0; i < width; i++) {
            delete[] maze[i];
        }
        delete [] maze;
    }
    
    void resetMaze() {
        clear();
        maze = new Cell*[width];
        for(int i = 0; i < width; i++)
            maze[i] = new Cell[length];
        for(int i = 0; i < width; i++) {
            for(int j = 0; j < length; j++) {
                Cell* temp = new Cell;
                maze[i][j] = *temp;
            }
        }
    }
    
    int* checkNeighbors(int col, int row) {
        int ln = col-1;
        int rn = col+1;
        int un = row-1;
        int dn = row+1;
        
        int validNeighbors[4];
        for(int i = 0; i < 4; i++)
            validNeighbors[i] = 0;
        if (ln > 0 && allWallsIntact(maze[ln][row]) && maze[ln][row].visited()==0) {
            validNeighbors[0] = 1;
        }
        if (rn < width && allWallsIntact(maze[rn][row]) && maze[rn][row].visited()==0) {
            validNeighbors[1] = 1;
        }
        if (un > 0 && allWallsIntact(maze[col][un]) && maze[col][un].visited()==0) {
            validNeighbors[2] = 1;
        }
        if (dn < length && allWallsIntact(maze[col][row]) && maze[col][row].visited()==0) {
            validNeighbors[3] = 1;
        }
        int* toReturn = validNeighbors;
        return toReturn;
    }
    bool allWallsIntact(Cell c) {
        return (c.left==NULL && c.right==NULL && c.up==NULL && c.down==NULL);
    }
    void initializeMaze() {
        resetMaze();
        
        stack<int *> *CellStack = new stack<int*>();
        int totalCells = length*width;
        int curCol = 0;
        int curRow = 0;
        Cell *CurrentCell = &maze[curCol][curRow];

        int VisitedCells = 1;
        
        while(VisitedCells < totalCells) {
            int* intactNeighors = checkNeighbors(curCol, curRow);
            
            bool allUsed = true;
            for(int i = 0; i <=3; i++) {
                if(intactNeighors[i]!=0)
                    allUsed = false;
            }
            if(!allUsed) {
                int num = rand() % 4;
                for(;intactNeighors[num]==1; num = rand()%4) {
                    int *loc = new int[2];
                    switch (num) {
                        case 0:
                            CurrentCell->visit();
                            CurrentCell->left = &maze[curCol-1][curRow];
                            maze[curCol-1][curRow].right = CurrentCell;
                            maze[curCol-1][curRow].parent = CurrentCell;
                            loc[0] = curCol;
                            loc[1] = curRow;
                            CellStack->push(loc);
                            curCol--;
                            break;
                        case 1:
                            CurrentCell->visit();
                            CurrentCell->right = &maze[curCol+1][curRow];
                            maze[curCol+1][curRow].left = CurrentCell;
                            maze[curCol+1][curRow].parent = CurrentCell;
                            loc[0] = curCol;
                            loc[1] = curRow;
                            CellStack->push(loc);
                            curCol++;
                            break;
                        case 2:
                            CurrentCell->visit();
                            CurrentCell->up = &maze[curCol][curRow-1];
                            maze[curCol][curRow-1].down = CurrentCell;
                            maze[curCol][curRow-1].parent = CurrentCell;
                            loc[0] = curCol;
                            loc[1] = curRow;
                            CellStack->push(loc);
                            curRow--;
                            break;
                        case 3:
                            CurrentCell->visit();
                            CurrentCell->down = &maze[curCol][curRow+1];
                            maze[curCol][curRow+1].up = CurrentCell;
                            maze[curCol][curRow+1].parent = CurrentCell;
                            loc[0] = curCol;
                            loc[1] = curRow;
                            CellStack->push(loc);
                            curRow++;
                            break;
                        default:
                            break;
                        break;
                    }
                }
                CurrentCell = &maze[curCol][curRow];
                VisitedCells++;
                
            } else {
                int *loc = CellStack->top();
                curCol = loc[0];
                curRow = loc[1];
                CurrentCell = &maze[curCol][curRow];
                CellStack->pop();
            }
        }
    }
    
    void solve() {
        
    }
    
    bool solve(Cell * cell, int step) {
        if(cell == NULL)
            return false;
        //solved
        if(cell == &maze[width-1][length-1])
            return true;
        if(cell->up!=NULL && cell->up!=cell->parent)
            return solve(cell->up, step++);
        if(cell->left!=NULL && cell->left!=cell->parent)
            return solve(cell->left, step++);
        if(cell->right!=NULL && cell->right!=cell->parent)
            return solve(cell->right, step++);
        if(cell->down!=NULL && cell->down!=cell->parent)
            return solve(cell->down, step++);
        return false;//solve(cell->parent, step++);
    }
    void print(){
        for(int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                
            }
        }
    }
    
};

#endif
