#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

//                                   Articulation point
/*
void dfs(int node, int parent, vector<int>& disc, vector<int>& low, unordered_map<int, bool>& vis, vector<int> adj[], set<int> &ap, int &timer) {
        
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    for(auto nbr: adj[node]) {
        if(nbr == parent) {
            continue;
        }
        if(!vis[nbr]) {
            dfs(nbr, node, disc, low, vis, adj, ap, timer);
            low[node] = min(low[node], low[nbr]);
            
            // Check AP or not
            if(low[nbr] >= disc[node] && parent != -1) {
                ap.insert(node);
            }
            child++;
        }
        else {
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if(child > 1 && parent == -1) {
        ap.insert(node);
    }
}
vector<int> articulationPoints(int V, vector<int> adj[]) {
    
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    unordered_map <int, bool> vis;
    set<int> ap;

    int timer = 0;
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            dfs(i, -1, disc, low, vis, adj, ap, timer);
        }
    }

    // Copy all elements of set in vector
    vector<int> v(ap.begin(), ap.end());
    sort(v.begin(), v.end());
    if(v.empty()) {
        v.push_back(-1);
        return v;
    }
    return v;
}
int main() {

    int V;
    cout << "Enter the number of nodes : " << endl;
    cin >> V;

    int E;
    cout << "Enter the number of edges : " << endl;
    cin >> E;

    // Creation of adjacency list
    vector<int> adj[V];
    cout << "Enter the edges : " << endl;
    for (int i=0; i<E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Result
    vector<int> ap = articulationPoints(V, adj);
    cout << "Articulation Points: ";
    for (int point : ap) {
        cout << point << " ";
    }
    cout << endl;

    return 0;
}
*/