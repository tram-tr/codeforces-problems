#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs (int i, int j, int n, int m, vector<vector<int>> &visited, vector<vector<char>> &maze) {
    queue<pair<int, int>> frontier;
    frontier.push({i,j});
    visited[i][j] = 1;
    int cells;
    while (!frontier.empty()) {
        auto curr = frontier.front();
        frontier.pop();

        int row = curr.first;
        int col = curr.second;
        cells++;

        if (row > 0 && maze[row-1][col] != '#' && visited[row-1][col] == 0) {
            frontier.push({row-1, col});
            visited[row-1][col] = 1;
        }
        if (col > 0 && maze[row][col-1] != '#' && visited[row][col-1] == 0) {
            frontier.push({row, col-1});
            visited[row][col-1] = 1;
        }
        if (row < n-1 && maze[row+1][col] != '#' && visited[row+1][col] == 0) {
            frontier.push({row+1, col});
            visited[row+1][col] = 1;
        }
        if (col < m-1 && maze[row][col+1] != '#' && visited[row][col+1] == 0) {
            frontier.push({row, col+1});
            visited[row][col+1] = 1;
        }
    }

    return cells;
}

int main(int argc, char *argv[]) {
    int tests;
    cin >> tests;

    for (int t = 0; t < tests; t++) {
        int n, m;
        cin >> m >> n;

        vector<vector<char>> map(n, vector<char>(m));
        vector<vector<int>> visited(n, vector<int>(m));
        int start_i, start_j;

        int openings = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
                visited[i][j] = 0;
                if (map[i][j] == '@') {
                    start_i = i;
                    start_j = j;
                }
            }
        }

        cout << "Case " << t + 1 << ": " << bfs(start_i, start_j, n, m, visited, map) << endl;
    }

    return 0;
}