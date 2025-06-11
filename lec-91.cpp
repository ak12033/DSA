#include <iostream>
#include <vector>
#include <unordered_map> 
#include <list> 
#include <queue>
using namespace std;

//                                Topological sort using BFS
//                                    (Kahn's Algorithm)
/*
vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {

    // Create adjacency list
    unordered_map <int, list<int>> adj;
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Find all indegrees
    vector<int> indegree(v); 
	for(auto i : adj) {
	    for(auto j : i.second) {
	        indegree[j]++; 
	    }
	}

    // 0 indegree walo ko push kardo
    queue <int> q;
    for(int i = 0; i<v; i++) {
	    if(indegree[i] == 0) {
	        q.push(i); 
        }
    }

    // Do BFS
    vector<int> ans;
    while(!q.empty()) {
	    int front = q.front(); 
	    q.pop(); 

        // Ans store
        ans.push_back(front);
	    
        for(auto neighbour : adj[front]) {
	        indegree[neighbour]--;
	        if(indegree[neighbour] == 0) {
	            q.push(neighbour); 
	        }
	    }
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

    vector<vector<int>> edges(m);
    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Result
    vector<int> result = topologicalSort(edges, n, m);
    cout << "Topological Sort Order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
*/