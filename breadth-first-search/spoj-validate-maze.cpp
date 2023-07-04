// https://www.spoj.com/problems/MAKEMAZE/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void bfs (int i, int j, int n, int m, vector<vector<int>> &visited, vector<vector<char>> &maze) {
    queue<pair<int, int>> frontier;
    frontier.push({i,j});
    visited[i][j] = 1;

    while (!frontier.empty()) {
        auto curr = frontier.front();
        frontier.pop();

        int row = curr.first;
        int col = curr.second;

        if (row > 0 && maze[row-1][col] == '.' && visited[row-1][col] == 0) {
            frontier.push({row-1, col});
            visited[row-1][col] = 1;
        }
        if (col > 0 && maze[row][col-1] == '.' && visited[row][col-1] == 0) {
            frontier.push({row, col-1});
            visited[row][col-1] = 1;
        }
        if (row < n-1 && maze[row+1][col] == '.' && visited[row+1][col] == 0) {
            frontier.push({row+1, col});
            visited[row+1][col] = 1;
        }
        if (col < m-1 && maze[row][col+1] == '.' && visited[row][col+1] == 0) {
            frontier.push({row, col+1});
            visited[row][col+1] = 1;
        }
    }
}

int main(int argc, char *argv[]) {
    int tests;
    cin >> tests;

    for (int t = 0; t < tests; t++) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> maze(n, vector<char>(m));
        vector<vector<int>> visited(n, vector<int>(m));
        int start_i, start_j, end_i, end_j;

        int openings = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> maze[i][j];
                visited[i][j] = 0;
                if ((i == 0 || j == 0 || i == (n - 1) || j == (m - 1)) && maze[i][j] == '.') {
                    openings++;
                    if (openings == 1) {
                        start_i = i;
                        start_j = j;
                    }
                    if (openings == 2) {
                        end_i = i;
                        end_j = j;
                    }
                }
            }
        }

        if (openings != 2) {
            cout << "invalid" << endl;
            continue;
        }

        bfs(start_i, start_j, n, m, visited, maze);
        if (visited[end_i][end_j] == 1)
            cout << "valid" << endl;
        else
            cout << "invalid" << endl;
    }

    return 0;
}