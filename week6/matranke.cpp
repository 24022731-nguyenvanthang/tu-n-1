#include <iostream>
#include <vector>
using namespace std;

class DirectedGraphMatrix {
private:
    int n;                                 // số đỉnh
    vector<vector<int>> adj;               // ma trận kề

public:
    // Khởi tạo ma trận n × n toàn 0
    DirectedGraphMatrix(int n) : n(n) {
        adj.assign(n, vector<int>(n, 0));
    }

    // Thêm cạnh có hướng từ u → v
    void addEdge(int u, int v) {
        adj[u][v] = 1;                     // chỉ 1 chiều
    }

    // In ma trận kề
    void printMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    DirectedGraphMatrix g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    g.printMatrix();

    return 0;
}
