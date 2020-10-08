// Madeline Eckhart
// AI Principles and Applications
// Homework 1
// PuzzleState.h
//

using namespace std;

#ifndef PuzzleState_h
#define PuzzleState_h

struct PuzzleState {

    PuzzleState* parent;

    array <int, 18> puzzle;

    int priority;
    int g;
    int h;
    int f;

    int level;
    int state_id;
};

PuzzleState* newState(array <int, 18> puzzle1, int, int state_id, int currPos, int newPos, int g, int h, int f, PuzzleState* parent);
int getCost(int tile);

#endif
