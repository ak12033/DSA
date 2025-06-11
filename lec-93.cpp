#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

//                             Shortest path in an unweighted graph
/*
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
	
	// Create adjacency list
    unordered_map <int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
		adj[v].push_back(u);
    }

	// Do BFS
	unordered_map <int, bool> visited;
    unordered_map <int, int> parent;
	queue <int> q;
    q.push(s);
	parent[s] = -1;
    visited[s] = true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(auto i : adj[front]) {
            if (!visited[i]) {
            	visited[i] = true;
				parent[i] = front;
				q.push(i); 
            }
        }
    }

	// Prepare shortest path
	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);
	while(currentNode != s) {
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    int s, t;
    cout << "Enter the start node and target node: ";
    cin >> s >> t;

    vector<pair<int, int>> edges(m);
    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Result
    vector<int> path = shortestPath(edges, n, m, s, t);
    if (path.empty()) {
        cout << "No path exists from node " << s << " to node " << t << endl;
    } 
    else {
        cout << "Shortest path from node " << s << " to node " << t << ": ";
        for (int node : path) {
            cout << node;
            if(node != t) {
            cout << "->";
            } 
        }
        cout << endl;
    }
    return 0;
}
*/