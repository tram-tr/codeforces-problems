// https://codeforces.com/problemset/problem/673/A

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, t;
  cin >> n;
  int time[91] = {0};
  while (cin >> t)
    time[t] = 1;
  
  int count = 0;
  int i;
  for (i = 1; i <= 90; i++) {
    if (time[i] == 1)
      count = 0;
    else {
      count++;
      if (count == 15) {
        break;
      }
    }
  }
  
  if (i == 91)
    cout << i - 1;
  else 
    cout << i;
  
  return 0;
}
