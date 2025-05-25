#include <iostream>
using namespace std;

#define MAX_NODES 100

class GameMap {
    int numNodes;
    int adjMatrix[MAX_NODES][MAX_NODES];

public:
    GameMap(int nodes) {
        numNodes = nodes;
        for (int i = 0; i < numNodes; i++)
            for (int j = 0; j < numNodes; j++)
                adjMatrix[i][j] = -1;
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = adjMatrix[v][u] = weight;
    }

    void BFS(int start) {
        bool visited[MAX_NODES] = {false};
        int distance[MAX_NODES], queue[MAX_NODES], front = 0, rear = 0;
        
        for (int i = 0; i < numNodes; i++)
            distance[i] = MAX_NODES;
        distance[start] = 0;
        visited[start] = true;
        queue[rear++] = start;

        while (front < rear) {
            int node = queue[front++];
            for (int neighbor = 0; neighbor < numNodes; neighbor++) {
                if (adjMatrix[node][neighbor] != -1 && !visited[neighbor]) {
                    int newDist = distance[node] + adjMatrix[node][neighbor];
                    if (newDist < distance[neighbor])
                        distance[neighbor] = newDist;
                    visited[neighbor] = true;
                    queue[rear++] = neighbor;
                }
            }
        }

        for (int i = 0; i < numNodes; i++) {
            cout << "Distance from " << start + 1 << " to " << i + 1 << ": ";
            cout << (distance[i] == MAX_NODES ? "Unreachable" : to_string(distance[i])) << endl;
        }
    }

    bool isConnected() {
        bool visited[MAX_NODES] = {false};
        int stack[MAX_NODES], top = 0;
        stack[top++] = 0;
        visited[0] = true;

        while (top > 0) {
            int node = stack[--top];
            for (int neighbor = 0; neighbor < numNodes; neighbor++) {
                if (adjMatrix[node][neighbor] != -1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    stack[top++] = neighbor;
                }
            }
        }

        for (int i = 0; i < numNodes; i++)
            if (!visited[i]) return false;
        return true;
    }
};

int main() {
    int nodes, edges, u, v, weight, start;
    
    cout << "Welcome to the Multiplayer Game Map!\n";
    cout << "Enter the number of zones (nodes): ";
    cin >> nodes;

    if (nodes <= 0 || nodes > MAX_NODES) {
        cout << "Invalid number of nodes. (1-" << MAX_NODES << ")\n";
        return 1;
    }

    GameMap game(nodes);

    cout << "Enter the number of edges: ";
    cin >> edges;
    if (edges < 0) {
        cout << "Number of edges cannot be negative.\n";
        return 1;
    }

    for (int i = 0; i < edges; i++) {
        cout << "Edge " << i + 1 << ":\n";
        cout << "Start zone [1-based]: "; cin >> u;
        cout << "Destination zone [1-based]: "; cin >> v;
        cout << "Weight (0 for teleportation): "; cin >> weight;
        u--; v--;

        if (u < 0 || u >= nodes || v < 0 || v >= nodes || weight < 0) {
            cout << "Invalid edge input.\n";
            return 1;
        }
        game.addEdge(u, v, weight);
    }

    cout << "======================================\n";
    cout << "Enter the start zone [1-based]: ";
    cin >> start;
    start--;

    if (start < 0 || start >= nodes) {
        cout << "Invalid start zone.\n";
        return 1;
    }

    game.BFS(start);

    cout << (game.isConnected() ? "All zones are reachable." : "Not all zones are reachable.") << endl;
    return 0;
}
