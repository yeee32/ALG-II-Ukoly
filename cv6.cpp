#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct State {
    int farmer = 0; 
    int sheep = 0; 
    int wolf = 0; 
    int cabbage = 0; 
    // 0 vlevo
    // 1 vpravo
    vector<string> path; 

    bool operator==(const State &other) const {
        return farmer == other.farmer && sheep == other.sheep && wolf == other.wolf && cabbage == other.cabbage;
    }
};

bool isSafe(State* state) {
    if(state->farmer != state->sheep){
        if(state->sheep == state->wolf){
            return false; 
        } 
        if(state->sheep == state->cabbage){
            return false;
        } 
    }
    return true;
}

vector<State> getNextStates(State side) {
    vector<State> finalMoves;
    int newSide = 1 - side.farmer;
    
    State move = side;       
    move.farmer = newSide;
    move.path.push_back("Farmer crosses alone");
    if(isSafe(&move)){
        finalMoves.push_back(move);
    } 

    if(side.sheep == side.farmer){
        State move = side;
        move.farmer = newSide;
        move.sheep = newSide;
        move.path.push_back("Farmer takes Goat");
        if(isSafe(&move)){
            finalMoves.push_back(move);
        } 
    }

    if(side.wolf == side.farmer){
        State move = side;
        move.farmer = newSide;
        move.wolf = newSide;
        move.path.push_back("Farmer takes Wolf");
        if(isSafe(&move)){
            finalMoves.push_back(move);
        } 
    }

    if(side.cabbage == side.farmer){
        State move = side;
        move.farmer = newSide;
        move.cabbage = newSide;
        move.path.push_back("Farmer takes Cabbage");
        if(isSafe(&move)){
            finalMoves.push_back(move);
        }
    }

    return finalMoves;
}

bool visited(vector<State> visitedStates, State state) {
    for(auto visited : visitedStates){
        if(visited == state){
            return true;
        } 
    }
    return false;
}

int main() {
    State start = {0,0,0,0, {}};
    State end  = {1,1,1,1, {}};

    queue<State> stateQueue;
    stateQueue.push(start);
    vector<State> visitedStates;
    visitedStates.push_back(start);

    int step_i = 1;
    
    while(!stateQueue.empty()) {
        State curr = stateQueue.front(); 
        stateQueue.pop();
        if(curr == end) {
            for(auto step : curr.path) {
                cout << "Step " << step_i <<": "<< step << endl;
                step_i++;
            }
            return 0;
        }

        vector<State> nextStates = getNextStates(curr);
        for(auto next : nextStates){
            if(!visited(visitedStates, next)){
                visitedStates.push_back(next);
                stateQueue.push(next);
            }
        }
    }

    return 0;
}
