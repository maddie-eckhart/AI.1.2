// Madeline Eckhart
// AI Principles and Applications
// Homework 1
// Astar.cpp
//

#include <vector>
#include <iostream>
#include <queue>
#include <array>
#include <algorithm>
#include "PuzzleState.h"

using namespace std;

struct PriorityQueuePreferencesh1 {
    bool operator()(PuzzleState* lhs, PuzzleState* rhs) const {
        return lhs -> f > rhs -> f;
    }
};

int getEmptyIndex(array <int, 18> state) {
    for (int i = 0; i < 18; i++) {
        if (state[i] == 0) return i;
    }
    return 0;
}

void printArr(array <int, 18> arr) {
    for (int i = 0; i < 18; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool checkIfGoalState(PuzzleState* start, PuzzleState* goal, int closed, int open) {
    for ( int i = 0; i < 18; i++ ) {
        if ( start -> puzzle[i] != goal -> puzzle[i]) {
            cout << "Not in goal state" << endl;
            return false;
        }
    }

    // goal state reached
    cout << "Goal Reached" << endl;
    cout << "Number of moves: " << start -> level << endl;
    cout << "Closed List size: " << closed << endl;
    cout << "Open List size: " << open << endl;

    return true;
}

int getG(int tile) {
    switch (tile) {
        case 0: return 0;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6: return 1;
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16: return 3;
        case 17: return 15;
    }
    return 0;
}

int getH(PuzzleState* curr, PuzzleState* goal) {
    int h = 0;
    for ( int i = 0; i < 18; i++ ) {
        if ( curr -> puzzle[i] != goal -> puzzle[i]) {
            h++;
        }
    }
    return h;
}

void h1(PuzzleState* start, PuzzleState* goal) {
    
    vector <PuzzleState*> closed;
    array <int, 18> empty = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    closed.push_back(newState(empty, 0, 0, 0, 0, 0, 0, 0, NULL));
    
    priority_queue<PuzzleState*, vector<PuzzleState*>, PriorityQueuePreferencesh1> open;
    open.push(start);
    
    int level = 0;
    int set_id = 1;
    int G = 0;
    int H = 0;
    int F = 0;
    
    while (!open.empty()) {
        PuzzleState* curr = open.top();
        
        open.pop();
        
        cout << "State array: ";
        printArr(curr -> puzzle);
        
        if (checkIfGoalState(curr, goal, closed.size(), open.size())) return;
        level++;
        
        int empty = getEmptyIndex(curr -> puzzle);
//        cout << "Empty state index: " << empty << endl;
        
        vector <PuzzleState*> newSuccessors;
        
        // Find all successor states of S
        
        switch (empty) {
            case 0:
                set_id++;
                G = getG(1);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 0, 1, G, H, F, curr -> parent)); // move right
                set_id++;
                G = getG(3);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 0, 3, G, H, F, curr -> parent)); // move down
                break;
            case 1:
                set_id++;
                G = getG(0);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 1, 0, G, H, F, curr -> parent)); // move left
                set_id++;
                G = getG(2);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 1, 2, G, H, F, curr -> parent)); // move right
                set_id++;
                G = getG(4);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 1, 4, G, H, F, curr -> parent)); // move down
                break;
            case 2:
                set_id++;
                G = getG(1);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 2, 1, G, H, F, curr -> parent)); // move left
                set_id++;
                G = getG(5);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 2, 5, G, H, F, curr -> parent)); // move down
                break;
            case 3:
                set_id++;
                G = getG(0);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 3, 0, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(4);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 3, 4, G, H, F, curr -> parent)); // move right
                set_id++;
                G = getG(6);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 3, 6, G, H, F, curr -> parent)); // move down
                break;
            case 4:
                set_id++;
                G = getG(3);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 4, 3, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(5);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 4, 5, G, H, F, curr -> parent)); // move right
                set_id++;
                G = getG(7);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 4, 7, G, H, F, curr -> parent)); // move down
                set_id++;
                G = getG(3);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 4, 3, G, H, F, curr -> parent)); // move left
                break;
            case 5:
                set_id++;
                G = getG(2);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 5, 2, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(8);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 5, 8, G, H, F, curr -> parent)); // move down
                set_id++;
                G = getG(4);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 5, 4, G, H, F, curr -> parent)); // move left
                break;
            case 6:
                set_id++;
                G = getG(3);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 6, 3, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(7);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 6, 7, G, H, F, curr -> parent)); // move right
                set_id++;
                G = getG(9);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 6, 9, G, H, F, curr -> parent)); // move down
                break;
            case 7:
                set_id++;
                G = getG(4);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 7, 4, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(8);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 7, 8, G, H, F, curr -> parent)); // move right
                set_id++;
                G = getG(10);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 7, 10, G, H, F, curr -> parent)); // move down
                set_id++;
                G = getG(6);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 7, 6, G, H, F, curr -> parent)); // move left
                break;
            case 8:
                set_id++;
                G = getG(5);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 8, 5, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(11);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 8, 11, G, H, F, curr -> parent)); // move down
                set_id++;
                G = getG(7);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 8, 7, G, H, F, curr -> parent)); // move left
                break;
            case 9:
                set_id++;
                G = getG(6);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 9, 6, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(10);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 9, 10, G, H, F, curr -> parent)); // move right
                set_id++;
                G = getG(12);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 9, 12, G, H, F, curr -> parent)); // move down
                break;
            case 10:
                set_id++;
                G = getG(7);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 10, 7, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(11);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 10, 11, G, H, F, curr -> parent)); // move right
                set_id++;
                G = getG(13);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 10, 13, G, H, F, curr -> parent)); // move down
                set_id++;
                G = getG(9);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 10, 9, G, H, F, curr -> parent)); // move left
                break;
            case 11:
                set_id++;
                G = getG(8);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 11, 8, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(14);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 11, 14, G, H, F, curr -> parent)); // move down
                set_id++;
                G = getG(10);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 11, 10, G, H, F, curr -> parent)); // move left
                break;
            case 12:
                set_id++;
                G = getG(9);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 12, 9, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(13);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 12, 13, G, H, F, curr -> parent)); // move right
                set_id++;
                G = getG(15);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 12, 15, G, H, F, curr -> parent)); // move down
                break;
            case 13:
                set_id++;
                G = getG(10);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 13, 10, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(14);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 13, 14, G, H, F, curr -> parent)); // move right
                set_id++;
                G = getG(16);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 13, 16, G, H, F, curr -> parent)); // move down
                set_id++;
                G = getG(12);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 13, 12, G, H, F, curr -> parent)); // move left
                break;
            case 14:
                set_id++;
                G = getG(11);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 14, 11, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(17);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 14, 17, G, H, F, curr -> parent)); // move down
                set_id++;
                G = getG(13);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 14, 13, G, H, F, curr -> parent)); // move left
                break;
            case 15:
                set_id++;
                G = getG(12);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 15, 12, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(16);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 15, 16, G, H, F, curr -> parent)); // move right
                break;
            case 16:
                set_id++;
                G = getG(13);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 16, 13, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(17);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 16, 17, G, H, F, curr -> parent)); // move right
                set_id++;
                G = getG(15);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 16, 15, G, H, F, curr -> parent)); // move left
                break;
            case 17:
                set_id++;
                G = getG(14);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 17, 14, G, H, F, curr -> parent)); // move up
                set_id++;
                G = getG(16);
                H = getH(curr, goal);
                F = G + H;
                newSuccessors.push_back(newState(curr -> puzzle, level, set_id, 17, 16, G, H, F, curr -> parent)); // move left
                break;
        }
        
        // insert new states into open list
        for (int i = 0; i < newSuccessors.size(); i++) {
//            printArr(newSuccessors[i] -> puzzle);
            // check if new states are already in the closed list (ignore if they are)
            for (int j = 0; j < closed.size(); j++) {
                if (closed[j] -> puzzle != newSuccessors[i] -> puzzle) {
                    open.push(newSuccessors[i]);
                    break;
                }
            }
        }

        newSuccessors.clear();
        
        cout << "G: " << G << ", H: " << H << ", F: " << F << endl;
        cout << "Level: " << level << endl;
        cout << "Closed List size: " << closed.size() << endl;
        cout << "Open List size: " << open.size() << endl << endl;
        
        // place rejected state into the closed list
        closed.push_back(curr);
    }

}

