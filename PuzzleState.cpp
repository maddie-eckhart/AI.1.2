// Madeline Eckhart
// AI Principles and Applications
// Homework 1
// PuzzleState.cpp
//

#include <iostream>
#include <array>
#include "PuzzleState.h"

using namespace std;

PuzzleState* newState(array <int, 18> puzzle1, int level, int state_id, int currPos, int newPos, int g, int h, int f, PuzzleState* parent) {
    
    PuzzleState* state = new PuzzleState;
  
    state -> parent = parent;
  
    // copy data from parent node to current node
    state -> puzzle = puzzle1;
  
    // move tile
    swap(state -> puzzle[currPos], state -> puzzle[newPos]);
  
    // set level
    state -> level = level;
    
    // set id
    state -> state_id = state_id;
    
    // set g, h, f
    state -> g = g;
    
    state -> h = h;
    
    state -> f = f;
    
    return state;
}


