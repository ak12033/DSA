#include <iostream>
#include <vector>
#include <unordered_map> 
#include <queue>
#include <list> 
using namespace std;

//                             Detect Cycle In A Directed Graph
/*
int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {

    // Create adjacency list
    unordered_map <int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adj[u].push_back(v);
    }

    // Find all indegrees
    vector<int> indegree(n); 
	for(auto i : adj) {
	    for(auto j : i.second) {
	        indegree[j]++; 
	    }
	}

    // 0 indegree walo ko push kardo
    queue <int> q;
    for(int i=0; i<n; i++) {
	    if(indegree[i] == 0) {
	        q.push(i); 
        }
    }

    // Do BFS
    int count = 0;
    while(!q.empty()) {
	    int front = q.front(); 
	    q.pop();  
        count++;
        for(auto neighbour : adj[front]) {
	        indegree[neighbour]--;
	        if(indegree[neighbour] == 0) {
	            q.push(neighbour); 
	        }
	    }
	}
    if(count == n) {
        return false;
    }
    else {
        return true;
    }
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    vector<pair<int, int>> edges(m);
    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Detect cycle in the directed graph
    if(detectCycleInDirectedGraph(n, edges)) {
        cout << "The graph contains a cycle." << endl;
    } 
    else {
        cout << "The graph does not contain a cycle." << endl;
    }
    return 0;
}
*/