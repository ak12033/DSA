#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <limits.h>
using namespace std;

//                          Shortest path in Directed Acyclic Graph 
/*
class Graph {

    public:
        unordered_map <int, list <pair<int, int>>> adj;
      
        void addEdge(int u, int v, int weight) {

            pair<int, int> p = make_pair(v, weight);
            adj[u].push_back(p);
        }
        void printAdj() {

            for(auto i : adj) {
                cout << i.first << "->";
                for(auto j : i.second) {
                    cout << "(" << j.first << "," << j.second << "),";
                }
                cout << endl;
            }
        }
        void dfs(int node, unordered_map <int, bool>& vis, stack <int>& topo) {

            vis[node] = true;
            for(auto neighbour : adj[node]) {
                if(!vis[neighbour.first]) {
                    dfs(neighbour.first, vis, topo);
                }
            }
            topo.push(node);
        }
        void getShortestPath(int src, vector<int>& dist, stack <int>& topo) {

            dist[src] = 0;
            while(!topo.empty()) {
                int top = topo.top();
                topo.pop();
                if(dist[top] != INT_MAX) {
                    for(auto i : adj[top]) {
                        if(dist[top] + i.second < dist[i.first]) {
                            dist[i.first] = dist[top] + i.second;
                        }
                    }
                }
            }
        }
};
int main() {

    Graph g;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    
    // Adjacency List
    g.printAdj();

    // Topological sort
    unordered_map <int, bool> visited;
    stack <int> s;

    int n = 6;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            g.dfs(i, visited, s);
        }
    }

    vector<int> dist(n);

    int src = 1;
    for(int i=0; i<n; i++) {
        dist[i] = INT_MAX;
    }
    g.getShortestPath(src, dist, s);

    cout << "Answer is: " << endl;
    for(int i=0; i<dist.size(); i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                          OR
/*
void dfs(int node, unordered_map <int, bool>& vis, stack <int>& topo, unordered_map <int, list <pair<int, int>>> &adj) {

    vis[node] = true;
    for(auto neighbour : adj[node]) {
        if(!vis[neighbour.first]) {
            dfs(neighbour.first, vis, topo, adj);
        }
    }
    topo.push(node);
}
void getShortestPath(int src, vector<int>& dist, stack <int>& topo, unordered_map <int, list <pair<int, int>>> &adj) {

    dist[src] = 0;
    while(!topo.empty()) {
        int top = topo.top();
        topo.pop();
        if(dist[top] != INT_MAX) {
            for(auto i : adj[top]) {
                if(dist[top] + i.second < dist[i.first]) {
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }
}
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
    // Creating Adjacency List
    unordered_map <int, list <pair<int, int>>> adj;
    for(int i=0; i<E; i++) {
        pair<int, int> p = make_pair(edges[i][1], edges[i][2]);
        adj[edges[i][0]].push_back(p);
    }
    
    // Topological sort
    unordered_map <int, bool> visited;
    stack <int> s;
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            dfs(i, visited, s, adj);
        }
    }
    
    // Result
    vector<int> dist(V, INT_MAX);
    int src = 0;
    getShortestPath(src, dist, s, adj);
    for(int i=0; i<V; i++) {
        if(dist[i] == INT_MAX) {
            dist[i] = -1;
        };
    }
    return dist;
}
int main(){

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

    // Result
    vector<int> ans = shortestPath(n, m, edges);
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
*/