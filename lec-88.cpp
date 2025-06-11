#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <string>
using namespace std;

//                             Cycle Detection In Undirected Graph

//                                         Aproach 1
/*
bool isCyclicBFS(int src, unordered_map <int, bool>& visited, unordered_map <int, list<int>>& adj){

    unordered_map <int, int> parent;
    queue<int> q;

    parent[src] = -1;
    visited[src] = 1;
    q.push(src);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(auto neighbour : adj[front]) {
            if(visited[neighbour] == true && neighbour != parent[front]) {
                return true;
            }
            else if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m) {

    // Create adjacency list
    unordered_map <int, list<int>> adj;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // To handle disconnected components 
    unordered_map <int, bool> visited;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            bool ans = isCyclicBFS(i, visited, adj);
            if(ans == 1) {
                return "Yes";
            } 
        }
    }
    return "No";
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges : " << endl;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Detect cycle
    string result = cycleDetection(edges, n, m);
    cout << "Cycle detected: " << result << endl;

    return 0;
}
*/
//                                         Aproach 2
/*
bool isCyclicDFS(int node, int parent, unordered_map <int, bool>& visited, unordered_map <int, list<int>>& adj) {

    visited[node] = true;
    for(auto neighbour : adj[node]) {
        if(!visited[neighbour]) {
            bool cycledetected = isCyclicDFS(neighbour, node, visited, adj);
            if(cycledetected) {
                return true;
            }
        }
        // Cycle present
        else if(neighbour != parent) {
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m) {

    // Create adjacency list
    unordered_map <int, list<int>> adj;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // To handle disconnected components 
    unordered_map <int, bool> visited;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans == 1) {
                return "Yes";
            } 
        }
    }
    return "No";
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges : " << endl;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Detect cycle
    string result = cycleDetection(edges, n, m);
    cout << "Cycle detected: " << result << endl;

    return 0;
}
*/
//                                         Aproach 3
/*
bool isCyclicBFS(int node, unordered_map <int, bool>& visited, unordered_map <int, list<int>>& adjList) {

    queue<int> q;

    q.push(node);
    visited[node] = true;
    while(!q.empty()) {
        node = q.front();
        q.pop();
        // Counter for already visited nodes
        int cnt = 0;
        // Traversing the adjacency list
        for(int i : adjList[node]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            } 
            else {
                cnt++;
            }
        }
        // If the number of visited nodes in any adjacency list is >=2 then there is a cycle.
        if(cnt >= 2) {
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m) {

    // Create adjacency list
    unordered_map <int, list<int>> adj;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // To handle disconnected components 
    unordered_map <int, bool> visited;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            bool ans = isCyclicBFS(i, visited, adj);
            if(ans == 1) {
                return "Yes";
            } 
        }
    }
    return "No";
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges : " << endl;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Detect cycle
    string result = cycleDetection(edges, n, m);
    cout << "Cycle detected: " << result << endl;

    return 0;
}
*/
