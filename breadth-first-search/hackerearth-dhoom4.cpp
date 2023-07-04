// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/dhoom-4/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

void bfs (vector<int>&adj, int source, int target) {
    queue<int> frontier;
    vector<int> visited(100001, -1);

    frontier.push(source);
    visited[source] = 0;

    while (!frontier.empty()) {
        auto curr = frontier.front();
        frontier.pop();

        if (curr == target)
            break;
        
        for (auto v : adj) {
            int mul = (curr * v) % 100000;
            if (mul < 0) continue;
            if (visited[mul] == -1) {
                visited[mul] = visited[curr] + 1;
                frontier.push(mul);
            }
        }
    }

    cout << visited[target] << endl;
}

int main(int argc, char *argv[]) {
    int source, target;
    cin >> source >> target;
    int n;
    cin >> n;

    vector<int>adj;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        adj.push_back(v);
    }

    bfs(adj, source, target);

    return 0;
}
