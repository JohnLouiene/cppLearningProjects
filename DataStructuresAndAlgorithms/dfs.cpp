#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    // Example graph (adjacency list)
    // 0 -> 1, 2
    // 1 -> 2
    // 2 -> 0, 3
    // 3 -> 3
    vector<vector<int>> graph = {
        {1, 2}, // neighbors of 0
        {2},    // neighbors of 1
        {0, 3}, // neighbors of 2
        {3}     // neighbors of 3
    };

    vector<bool> visited(graph.size(), false);
    stack<int> s;

    int start = 0; // start DFS from node 0
    s.push(start);

    cout << "DFS traversal: ";
    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;

            // Push neighbors onto the stack
            // To get the same order as recursive DFS, push in reverse
            for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
                if (!visited[*it])
                    s.push(*it);
            }
        }
    }
    cout << endl;
    return 0;
}