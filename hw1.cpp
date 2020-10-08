// Madeline Eckhart
// AI Principles and Applications
// Homework 1
// hw1.cpp
//

#include <iostream>
#include <vector>
//#include "bfs.cpp"
#include "Astar.cpp"
#include "PuzzleState.h"

using namespace std;

PuzzleState* start;
PuzzleState* goal;

array <int, 18> startv;
array <int, 18> goalv;

int main() {
    int input = 0;
    
    //-- get start state --//
    cout << "Type in the start state separated by spaces" << endl;
    
    for (int i = 0; i < 18; i++) {
        cin >> input;
        startv[i] = input;
    }
    
    start = newState(startv, 0, 0, 0, 0, 0, 0, 0, NULL);

    //-- get goal state --//
    cout << "Type in the goal state separated by spaces" << endl;
    
    for (int i = 0; i < 18; i++) {
        cin >> input;
        goalv[i] = input;
    }

    goal = newState(goalv, 0, 0, 0, 0, 0, 0, 0, NULL);
    
    //-- BFS --//
//    cout << endl;
//    bfs(start, goal);
    
    //-- H1 --//
    cout << endl;
    h1(start, goal);
    
    return 0;
}

// cd Documents/AI/hw1
// g++ PuzzleState.cpp hw1.cpp
// ./a.out
