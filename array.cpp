// https://codeforces.com/problemset/problem/224/B

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

int main(int argc, char *argv[]) {
	size_t n, k;
  cin >> n >> k;
  size_t a[n];
  
 	unordered_map<size_t, size_t> map;
  size_t l = 0; 
  size_t r = -1;
  size_t count = 0;
  for (size_t i = 0; i < n; i++) {
    cin >> a[i]; 
    map[a[i]];
    if (map[a[i]] == 0)
      count++;
    if (r == -1) {
      if (count == k) r = i;
      map[a[i]]++;
    }
  }
  
  if (k > count)
    cout << "-1 -1";
  else {
    while (map[a[l]] > 1) {
      map[a[l]]--;
      l++;
    }
    cout << l+1 << " " << r+1;
  }
  
  return 0;
}
