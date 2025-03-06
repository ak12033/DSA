#include <iostream>
#include <vector>
#include <unordered_map> 
#include <queue>
#include <list>
#include <limits.h>
using namespace std;

//                                 Prim's Algorithm (MST)
//        To convert a graph into a tree with (n) number of nodes and (n-1) number of edges

//                                       Approach 1
/*
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>>& g) {

    // Create adj list for given particular node corresponding another node with its weight  
    unordered_map <int, list<pair<int, int>>> adj;
    for(int i=0; i<g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int weight = g[i].second;
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }

    // n+1 -> representing index number as a node
    // Weight of node 
    vector<int> key(n+1, INT_MAX);
    // Check whether given node is in mst  
    vector<bool> mst(n+1, false);  
    vector<int> parent(n+1, -1);

    // Mark source node as 0 and parent as -1 
    key[1] = 0;
    // For loop for (n-1) edges
    for(int i=1; i<n; i++) { 
        // Find minimum from key 
        int minimum = INT_MAX;
        int u;
        for(int v=1; v<=n; v++) {
            if(mst[v] == false && key[v] < minimum) {
                u = v;
                minimum = key[v];
            }
        }
        // Mark minimum node as true
        mst[u] = true;
 
        // Check u adjacent node 
        for(auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if(mst[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for(int i=2; i<=n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result; 
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    vector<pair<pair<int, int>, int>> edges(m);
    cout << "Enter the edges : " << endl;
    for (int i=0; i<m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges[i] = {{u, v}, weight};
    }

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);
    cout << "Edges in the MST:" << endl;
    for (auto edge : mst) {
        int u = edge.first.first;
        int v = edge.first.second;
        int weight = edge.second;
        cout << u << " - " << v << " : " << weight << endl;
    }
    return 0;
}
*/
//                               Approach 2 using min heap
/*
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>>& g) {
    
    // Create adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for(auto i : g) {
        int u = i.first.first;
        int v = i.first.second;
        int w = i.second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

		// Min heap to get node with minimum weight
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	  // Let source as 1 and inititally distance of source is 0 {weight, node}
		pq.push({0, 1});

    vector<int> key(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    vector<int> visited(n+1, 0);

		// Mark source node as 0 and parent as -1 
    key[1] = 0;
    while(pq.size()) {
        // Pull out minimum from MinHeap
        int w = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        // Mark visited of minimum node as true
        visited[node] = 1;
				// Check adjacent nodes of node 
        for(auto neighbour: adj[node]) {
            int toGo = neighbour.first;
            int toGoWeg = neighbour.second;
            if(!visited[toGo] && toGoWeg < key[toGo]) {
                key[toGo] = toGoWeg;
                parent[toGo] = node;
                pq.push({toGoWeg, toGo});
            }
        }

    }
    vector<pair<pair<int, int>, int>> ans;
		for(int i=2; i<=n; i++) {
        ans.push_back({{parent[i], i}, key[i]});

    }
    return ans;
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    vector<pair<pair<int, int>, int>> edges(m);
    cout << "Enter the edges : " << endl;
    for (int i=0; i<m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges[i] = {{u, v}, weight};
    }

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);
    cout << "Edges in the MST:" << endl;
    for (auto edge : mst) {
        int u = edge.first.first;
        int v = edge.first.second;
        int weight = edge.second;
        cout << u << " - " << v << " : " << weight << endl;
    }
    return 0;
}
*/