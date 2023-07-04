#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

typedef unordered_map<int, vector<int>> Undirected_Graph;
typedef queue<int> Frontier;
typedef set<int> Visited;

vector<int> bfs(Undirected_Graph& graph, int n, int s) {
    vector<int> distances(n+1, -1);     
    Frontier frontier;
    Visited visited;
    
    frontier.push(s);
    visited.insert(s);
    distances[s] = 0;

    while (!frontier.empty()) {
        auto curr = frontier.front();
        frontier.pop();
      
        for (auto &v : graph[curr]) {
          	if (visited.count(v))
              	continue;
            frontier.push(v);
            visited.insert(v);
            distances[v] = distances[curr] + 6;
        }
    }
  
  	distances.erase(distances.begin() + s); // remove the starting node distance
    return distances;
}

int main(int argc, char *argv[]) {
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int n, m;
        cin >> n >> m;
        
        Undirected_Graph graph;
        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            // bidirectional
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int s;
        cin >> s;
        
        vector<int> distances = bfs(graph, n, s);
        for (size_t j = 1; j < distances.size(); j++) {
            cout << distances[j];
            if (j != distances.size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
