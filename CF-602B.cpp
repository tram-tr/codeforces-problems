// https://codeforces.com/problemset/problem/602/B

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  unordered_map<int, int> visited;
  int max_length = -1;
  for (int i = 0; i < n; i++) {
    visited[a[i]-1];
    visited[a[i]+1];
    int prev = visited[a[i]-1];
    int next = visited[a[i]+1];
    int length;
    if (prev > next) {
      visited[a[i]-2];
      length = i - max(next, visited[a[i]-2]) + 1;
    }
    else {
      visited[a[i]+2];
      length = i - max(prev, visited[a[i]+2]) + 1;
    }
    max_length = max(length, max_length);
    visited[a[i]] = i + 1;
  }
  
  cout << max_length;
  
  return 0;
}
