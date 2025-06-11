#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//                                 Kruskal's Algorithm 

//                                Minimum Spanning Tree 
/*
bool cmp(vector<int>& a, vector<int>& b) {

    return a[2] < b[2];
}
void makeSet(vector<int>& parent, vector<int>& rank, int n) {

    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(vector<int>& parent, int node) {

    if(parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {

    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n) {

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    sort(edges.begin(), edges.end(), cmp);
  
    int minWeight = 0;
    for (int i=0; i<edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if (u != v) {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
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

    // Result
    int result = minimumSpanningTree(edges, n);
    cout << "Weight of the Minimum Spanning Tree: " << result << endl;

    return 0;
}
*/

