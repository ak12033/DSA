#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

//                                     Bellman Ford
/*
vector<int> bellmanFord(int V, int src, vector<vector<int>>& edges) {

    vector<int> dist(V, 1e8);
    dist[src] = 0;

    // n-1 times
    for(int i=1; i<V; i++) {
        // Traverse on edge list
        for(int j=0; j<edges.size(); j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u] != 1e8 && (dist[u] + wt < dist[v])) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // Check for negative cycle 
    bool flag = 0; 
    for(int j=0; j<edges.size(); j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if(dist[u] != 1e8 && (dist[u] + wt < dist[v])) {
            flag = 1;
        }
    }
    // If negative cycle is not present
    if(flag == 0) {
       return dist;
    }
    return {-1}; 
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    cout << "Enter the edges : " << endl;
    for (int i=0; i<m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<int> distances = bellmanFord(n, src, edges);

    if (distances.size() == 1) {
        cout << "Graph contains a negative weight cycle." << endl;
    } 
    else {
        cout << "Vertex distances from source " << src << ":" << endl;
        for (int i=0; i<n; i++) {
            cout << "Vertex " << i << ": " << distances[i] << endl;
        }
    }
    return 0;
}
*/