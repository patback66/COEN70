//
//  main.cpp
//  Lab8
//
//  Created by brian kevin pingel on 2/23/15.
//  Copyright (c) 2015 Brian Pingel & Matthew Koken. All rights reserved.
//

#include "expressiontree.h"

using namespace std;

/* 10 TEST CASES
 
 Add an equation: -3 5 + 4 2 - *
 The answer to the expression is 4
 
 Add an equation: 3 2 + 6 *
 The answer to the expression is 30
 
 Add an equation: 4 2 - 2 /
 The answer to the expression is 1
 
 Add an equation: 2 7 / 4 *
 The answer to the expression is 0
 
 Add an equation: 1 4 + 6 -
 The answer to the expression is -1
 
 Add an equation: 1 4 -
 The answer to the expression is -3
 
 Add an equation: 6 9 + 4 3 + /
 The answer to the expression is 2
 
 Add an equation: 2 4 / 2
 The answer to the expression is 0
 
 Add an equation: 1 3 - 45 *
 The answer to the expression is -90
 
 Add an equation: 1 5 * 3 9 / +
 The answer to the expression is 5
 
 */

int main(int argc, const char * argv[])
{
    ExpressionTree a;
    cout << a.evaluate() << endl;
    a.print_inorder(a.root);
    a.print_postorder(a.root);
    a.print_preorder(a.root);
}

