// https://codeforces.com/problemset/problem/161/A

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
 	int a[n];
  int b[m];
  
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  
  int ptr_a = 0; 
  int ptr_b = 0;
  int count = 0;
  vector<pair<int, int>> pairs;
  while (ptr_a < n && ptr_b < m) {
    int lower = a[ptr_a] - x;
    int upper = a[ptr_a] + y;
    if (lower <= b[ptr_b] && b[ptr_b] <= upper) {
      count++;
      pairs.push_back(make_pair(ptr_a+1, ptr_b+1));
      ptr_b++;
      ptr_a++;
    }
    else if (b[ptr_b] < lower)
      ptr_b++;
    else ptr_a++;
  }
  
  cout << count << endl;
  for (auto p : pairs)
    cout << p.first << " " << p.second << endl;
  
  return 0;
}
