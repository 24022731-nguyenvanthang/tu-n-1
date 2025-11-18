#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int n;                      // số đỉnh
    vector<vector<int>> adj;    // danh sách kề

public:
    Graph(int n) : n(n) {
        adj.assign(n, vector<int>());
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);    // đồ thị vô hướng
    }

    // DFS dùng đệ quy
    void dfsUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                dfsUtil(v, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(n, false);
        cout << "DFS: ";
        dfsUtil(start, visited);
        cout << endl;
    }

    // BFS dùng queue
    void BFS(int start) {
        vector<bool> visited(n, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }
};