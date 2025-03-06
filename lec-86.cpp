#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

//                                    BFS Traversal
/*
void prepareAdjList(unordered_map <int, set<int>>& adjList, vector<pair<int, int>>& edges) {

    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs(unordered_map <int, set<int>>& adjList, unordered_map <int, bool>& visited, vector<int>& ans, int node) {

    queue <int> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        // Store frontNode into ans
        ans.push_back(frontNode);
        
        // Traverse all neighbours of frontNode
        for(auto i : adjList[frontNode]) {
            if (!visited[i]) {
                q.push(i); 
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    
    vector<int> ans;
    unordered_map <int, set<int>> adjList;
    unordered_map <int, bool> visited;
    
    prepareAdjList(adjList,edges);
    
    // Travell all components of a graph
    for(int i=0; i<vertex; i++) {
        if(!visited[i]) {
            bfs(adjList, visited, ans, i);
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

    vector<pair<int, int>> edges(m);
    cout << "Enter the edges : " << endl;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Result
    vector<int> result = BFS(n, edges);
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
*/