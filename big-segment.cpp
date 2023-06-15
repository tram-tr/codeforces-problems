// https://codeforces.com/problemset/problem/242/B

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
  cin >> n;
  int l, r;
  int minl = 1000000000;
  int maxr = 0;
  int segment = -1;
  for (int i = 0; i < n; i++) {
  	cin >> l >> r;
    if (l <= minl && r >= maxr)
      segment = i + 1;
    else {
      if (l < minl || r > maxr)
        segment = -1;
    } 
    minl = min(l,minl);
    maxr = max(r,maxr);
  }
  
  cout << segment;
  return 0;
}
