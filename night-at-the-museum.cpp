// https://codeforces.com/problemset/problem/731/A

#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int rotation;
  int count = 0;
  char ptr = 'a';
  for (char c : s) {
    rotation = 26 - abs(c - ptr);
    if (rotation < 13)
      count += rotation;
    else
      count += 26 - rotation;
    ptr = c;
  }
  cout << count;
  return 0;
}
