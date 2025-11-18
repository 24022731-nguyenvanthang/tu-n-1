#include <iostream>
#include <vector>
using namespace std;

class EdgeListGraph {
private:
    vector<pair<int, int>> edges;   // danh sách cạnh (u, v)
    int n;                           // số đỉnh

public:
    EdgeListGraph(int n) : n(n) {}

    // thêm cạnh (vô hướng)
    void addEdge(int u, int v) {
        edges.push_back({u, v});
    }

    void print() {
        cout << "danhsachcanh:\n";
        for (auto &e : edges) {
            cout << e.first << " -- " << e.second << "\n";
        }
    }
};

int main() {
    EdgeListGraph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.print();

    return 0;
}
