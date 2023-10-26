#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printAdj() {
        for (pair<int, list<int>> i : adj) {
            cout << i.first << "->";
            for (int j : i.second) {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << endl;

    cout << "Enter the number of edges you want to enter: ";
    cin >> m;

    Graph g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
// here 0 means undirected 
    g.printAdj(); 
    return 0;
}
