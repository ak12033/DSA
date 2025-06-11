#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

//                                      Graph

//                        Implementation using Adjacency List

//                                    Approach 1
/*
class graph {

    public: 
        // Adjacency List
        unordered_map<int, list<int>> adj;  

        void addEdge(int u, int v, bool direction) {

            // Direction = 0 -> Undirected Graph
            // Direction = 1 -> Directed Graph

            adj[u].push_back(v);
            if(direction == 0) {
                adj[v].push_back(u);
            }
        } 
        void printAdjList() {

            for(auto i : adj) {
                cout << i.first << "->";
                for(auto j : i.second) {
                    cout << j << ", ";
                }
                cout << endl;
            }
        } 
};
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    graph g;

    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    cout << "Adjacency List:" << endl;
    g.printAdjList();

    return 0;    
}
*/
//                                Creating and Printing
/*
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {

    vector<int> ans[n];
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for (int i=0; i<n; i++) {
        adj[i].push_back(i);

        for(int j=0; j<ans[i].size(); j++) {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
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
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> adjList = printAdjacency(n, m, edges);
    cout << "Adjacency List:" << endl;
    for (auto row : adjList) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
*/

//                            Impementation using Adjacency Matrix
/*
class Graph {

    public:
        int numNodes;
        vector<vector<int>> adjMatrix;

        Graph(int n) {
            this->numNodes = n;
            adjMatrix.resize(n, vector<int>(n, 0));
        }
        void addEdge(int u, int v, int direction) {

            // Direction = 0 -> Undirected Graph
            // Direction = 1 -> Directed Graph

            adjMatrix[u][v] = 1;
            if (direction == 0) { 
                adjMatrix[v][u] = 1;
            }
        }
        void printAdjMatrix() {
            for (int i=0; i<numNodes; i++) {
                for (int j=0; j<numNodes; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    Graph g(n);

    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    cout << "Adjacency Matrix:" << endl;
    g.printAdjMatrix();

    return 0;
}
*/