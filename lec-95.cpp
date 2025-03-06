#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <limits.h>
using namespace std;

//                              Dijkstra's algorithm function
/*
vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {

    // Create adjajency list
    unordered_map <int, list <pair<int, int>>> adj;
    for(int i=0; i<edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Creation of distance array with infinite value initially 
    vector<int> dist(vertices, INT_MAX); 

    // Creation of set on basis(distance, node)
    set <pair<int, int>> st;

    // Initialize distance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0, source));
    while(!st.empty()) {   
        // Fetch top record
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        st.erase(st.begin());

        // Traverse on neighbours
        for(auto neighbour : adj[topNode]) {
            if(nodeDistance + neighbour.second < dist[neighbour.first]) {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                
                // If record found, then erase it
                if(record != st.end()) {
                    st.erase(record);
                }

                // Distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // Record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));      
            }
        }
    }
    return dist;
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;
    
    vector<vector<int>> edges(m, vector<int>(3));
    cout << "Enter the edges with weights: " << endl;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }

    // Run Dijkstra's algorithm
    vector<int> distances = dijkstra(edges, n, m, 0);
    cout << "Shortest distances from source node " << 0 << ":" << endl;
    for (int i=0; i<n; i++) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
*/