#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


int findParent(vector<int>& parent, int node) {

    if(parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}
void unionSet(int u, int v, vector<int>& parent, vector<int>& size) {

    u = findParent(parent, u);
    v = findParent(parent, v);

    if(size[u] < size[v]) {
        parent[u] = v;
        size[v] += size[u];
    }
    else if(size[u] > size[v]) {
        parent[v] = u;
        size[u] += size[v];
    }
    else {
        parent[v] = u;
        size[u] += size[v];
    }
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {

    vector<int> parent(n);
    vector<int> size(n);
    for(int i=0; i<n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    unordered_map <int, int> mp;
    for(int i=0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        unionSet(u, v, parent, size);
    }

    // Count the edges for each root
    for(int i=0; i < edges.size(); i++) {
        int u = edges[i][0];
        int root = findParent(parent, u);
        mp[root]++; 
    }

    int result = 0;
    for(int i=0; i<n; i++) {
        if(findParent(parent, i) == i) {
            int v = size[i];
            int e = mp[i];
            if((v * (v-1)) / 2 == e) {
                result++;
            }
        }
    }
    return result;
}