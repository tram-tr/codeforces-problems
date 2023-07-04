// https://codeforces.com/contest/279/problem/B

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, t;
  cin >> n >> t;

  int a[n+1];
  
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  int start = 0;
  int end = 0;
  int max_books = 0;
  int time = 0;
  
  a[n] = 1e9;
  while (end <= n) {
    if (time + a[end] <= t) {
      time += a[end];
      end++;
    }
    else {
      max_books = max(max_books, end - start);
      time -= a[start];
      start++;
    }
  }
  
  cout << max_books;
  
  return 0;
}
