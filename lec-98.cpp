#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

//                                                 Bridges In A Graph

void dfs(int node, int parent, vector<int> &discT, vector<int> &low, unordered_map< int, bool > &visited, vector<vector<int>> &result, unordered_map<int, list <int> > &adj, int &timer)
{
    visited[node] = true;
    discT[node] = low[node] = timer++;
    
    for(auto neighbour : adj[node])
    {
        if(neighbour == parent)
        {
            continue;
        }
        if(!visited[neighbour])
        {
            dfs(neighbour, node, discT, low, visited, result, adj, timer);
            low[node] =min(low[node], low[neighbour]);
            
            if(low[neighbour] > discT[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else
        {
             low[node] = min(low[node], discT[neighbour]);
        }
    }
    
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int, list <int> > adj;
    for(int i = 0; i<edges.size(); i++)
        {
          int u = edges[i][0];
          int v = edges[i][1];

          adj[u].push_back(v);
          adj[v].push_back(u);
        }
    int timer = 0;
    vector<int> discT(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map< int, bool > visited;
 
    //Initialize
    for(int i = 0; i<v; i++)
        {
          discT[i] = -1;
          low[i] = -1;
        }
    vector<vector<int>> result;
    //Call DFS
    for(int i = 0; i < v; i++)
        {
          if(!visited[i])
          {
            dfs(i, parent, discT, low, visited, result, adj, timer);
          }
        }
    return result;
}

int main() {
    int v, e;
    
    // Read the number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    
    vector<vector<int>> edges(e, vector<int>(2));
    
    // Read the edges
    cout << "Enter the edges (u v) one by one:\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    vector<vector<int>> bridges = findBridges(edges, v, e);
    
    // Print the bridges
    cout << "Bridges in the graph are:\n";
    for (const auto& bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }
    
    return 0;
}