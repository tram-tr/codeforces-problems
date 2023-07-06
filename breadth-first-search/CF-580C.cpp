// https://codeforces.com/problemset/problem/580/C
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <set>

using namespace std;

struct Node {
    int root;
    int temp;
    int total;
};

typedef unordered_map<int, vector<int>> Undirected_Graph;
typedef queue<Node> Frontier;
typedef set<int> Visited;

int bfs(Undirected_Graph &tree, vector<int>& cats, int m) {
    Frontier frontier;
    Visited visited;

    if (cats[1] <= m)
        frontier.push(Node {1, cats[1], cats[1]});

    int paths = 0;
    visited.insert(1);

    while (!frontier.empty()) {
        auto curr = frontier.front();
        frontier.pop();
      	
      	if(tree[curr.root].size() == 1 && curr.root != 1)
        		paths++;
      
        for (auto v : tree[curr.root]) {
            if (visited.count(v)) continue;
            visited.insert(v);
            
            int temp = curr.temp;
            int total = curr.total;
            if (cats[v] == 0)
                temp = 0;
            else {
                if (cats[curr.root] == 1)
                    temp++;
                else
                    temp = 1;
            }
            total = max(total, temp);
            if (total <= m)
                frontier.push(Node {v, temp, total});
        }
    }
    return paths;
}

int main(int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
  
    vector<int>cats(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }
  
    Undirected_Graph tree;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << bfs(tree, cats, m) << endl;

    return 0;
}
