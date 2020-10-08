// Madeline Eckhart
// AI Principles and Applications
// Homework 1
// bfs.cpp
//

#include <vector>
#include <iostream>
#include <queue>
#include <array>
#include <algorithm>
#include "PuzzleState.h"

using namespace std;

struct PriorityQueuePreferences {
    bool operator()(PuzzleState* lhs, PuzzleState* rhs) const {
        return lhs -> state_id < rhs -> state_id;
    }
};

int getEmptyIndex(array <int, 18> state) {
    for (int i = 0; i < 18; i++) {
        if (state[i] == 0) return i;
    }
    return 0;
}

void printFinalPath(PuzzleState* start) {
    if (start == NULL)
        return;
    printFinalPath(start -> parent);
    printf("\n");
}

void printArr(array <int, 18> arr) {
    for (int i = 0; i < 18; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool checkIfGoalState(PuzzleState* start, PuzzleState* goal) {
    for ( int i = 0; i < 18; i++ ) {
        if ( start -> puzzle[i] != goal -> puzzle[i]) {
            cout << "Goal State not reached" << endl;
            return false;
        }
    }
    
    // goal state reached
    cout << "Goal Reached" << endl;
    printFinalPath(start);
    
    return true;
}

void bfs(PuzzleState* start, PuzzleState* goal) {
    
    vector <PuzzleState*> closed;
    array <int, 18> empty = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    closed.push_back(newState(empty, 0, 0, 0, 0, NULL));
    
    priority_queue<PuzzleState*, vector<PuzzleState*>, PriorityQueuePreferences> open;
    open.push(start);
    
    int level = 0;
    int set_id = 1;
    
    while (!open.empty()) {
        PuzzleState* curr = open.top();
        
        open.pop();
        
        if (checkIfGoalState(curr, goal)) return;
        
        int empty = getEmptyIndex(curr -> puzzle);
        cout << "Empty state index: " << empty << endl;
        
        vector <PuzzleState*> newSuccessors;
        
        // Find all successor states of S
        
        switch (empty) {
            case 0:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 0, 1, curr -> parent)); // move right
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 0, 3, curr -> parent)); // move down
                break;
            case 1:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 1, 0, curr -> parent)); // move left
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 1, 2, curr -> parent)); // move right
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 1, 4, curr -> parent)); // move down
                break;
            case 2:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 2, 1, curr -> parent)); // move left
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 2, 5, curr -> parent)); // move down
                break;
            case 3:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 3, 0, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 3, 4, curr -> parent)); // move right
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 3, 6, curr -> parent)); // move down
                break;
            case 4:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 4, 3, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 4, 5, curr -> parent)); // move right
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 4, 7, curr -> parent)); // move down
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 4, 3, curr -> parent)); // move left
                break;
            case 5:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 5, 2, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 5, 8, curr -> parent)); // move down
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 5, 4, curr -> parent)); // move left
                break;
            case 6:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 6, 3, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 6, 7, curr -> parent)); // move right
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 6, 9, curr -> parent)); // move down
                break;
            case 7:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 7, 4, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 7, 8, curr -> parent)); // move right
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 7, 10, curr -> parent)); // move down
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 7, 6, curr -> parent)); // move left
                break;
            case 8:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 8, 5, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 8, 11, curr -> parent)); // move down
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 8, 7, curr -> parent)); // move left
                break;
            case 9:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 9, 6, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 9, 10, curr -> parent)); // move right
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 9, 12, curr -> parent)); // move down
                break;
            case 10:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 10, 7, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 10, 11, curr -> parent)); // move right
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 10, 13, curr -> parent)); // move down
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 10, 9, curr -> parent)); // move left
                break;
            case 11:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 11, 8, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 11, 14, curr -> parent)); // move down
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 11, 10, curr -> parent)); // move left
                break;
            case 12:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 12, 9, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 12, 13, curr -> parent)); // move right
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 12, 15, curr -> parent)); // move down
                break;
            case 13:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 13, 10, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 13, 14, curr -> parent)); // move right
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 13, 16, curr -> parent)); // move down
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 13, 12, curr -> parent)); // move left
                break;
            case 14:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 14, 11, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 14, 17, curr -> parent)); // move down
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 14, 13, curr -> parent)); // move left
                break;
            case 15:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 15, 12, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 15, 16, curr -> parent)); // move right
                break;
            case 16:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 16, 13, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 16, 17, curr -> parent)); // move right
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 16, 15, curr -> parent)); // move left
                break;
            case 17:
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 17, 14, curr -> parent)); // move up
                set_id++;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 17, 16, curr -> parent)); // move left
                break;
        }
        
        // insert new states into open list
        for (int i = 0; i < newSuccessors.size(); i++) {
            printArr(newSuccessors[i] -> puzzle);
            // check if new states are already in the closed list (ignore if they are)
            for (int j = 0; j < closed.size(); j++) {
                if (closed[j] -> puzzle != newSuccessors[i] -> puzzle) {
                    open.push(newSuccessors[i]);
                    break;
                }
            }
        }

        newSuccessors.clear();
        
        // place rejected state into the closed list
        cout << "Closed List size: " << closed.size() << endl;
        closed.push_back(curr);
        level++;
    }

}

