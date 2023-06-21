// https://codeforces.com/problemset/problem/387/B

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;

  int a[n+1];
  int b[m+1];
  
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < m; i++) 
    cin >> b[i];

  int ptr_a = 0, ptr_b = 0;
  while (ptr_a < n && ptr_b < m) {
    if (b[ptr_b] >= a[ptr_a]) {
      ptr_a++;
      ptr_b++;
    } 
    else ptr_b++;
  }

  cout << n - ptr_a << endl;

  return 0;
}
