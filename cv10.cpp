#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

void jarnik(vector<vector<int>>& graph){
    int graphSize = graph.size();

    vector<int> minVertex(graphSize, INT32_MAX);
    vector<bool> inMST(graphSize, false);
    vector<int> parent(graphSize, -1);

    minVertex[0] = 0;

    for(int i = 0; i < graphSize - 1; i++){
        int u = -1;
        for(int j = 0; j < graphSize; j++){
            if(!inMST[j] && (u == -1 || minVertex[j] < minVertex[u])){
                u = j;
            }
        }

        inMST[u] = true;

        for (int j = 0; j < graphSize; j++) {
            if (graph[u][j] != 0 && !inMST[j] && graph[u][j] < minVertex[j]) {
                minVertex[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    for (int v = 1; v < graphSize; v++) {
        cout << parent[v] << " - " << v << " (" << graph[v][parent[v]] << ")\n";
    }
}

vector<vector<int>> getInput(){
    vector<vector<int>> graph;
    int n = 5; 

    graph.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    return graph;
}

int main(){
    vector<vector<int>> g = getInput();
    jarnik(g);

    return 0;
}