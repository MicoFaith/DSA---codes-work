#include <iostream>
#include <vector>
#include <list>

using namespace std;

class GraphAdjList {
private:
    int vertices;
    vector<list<int>> adjList;

public:
    GraphAdjList(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove for directed graph
    }

    void display() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V = 5;
    GraphAdjList graph(V);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    graph.display();

    return 0;
}

