// https://codeforces.com/problemset/problem/691/A

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, button;
  cin >> n;
  int count = 0;
  while (cin >> button) {
  	if (button == 0)
      count++;
   	if (count > 1)
      break;
  }
  if (n == 1) {
    if (count == 0) cout << "YES";
    else cout << "NO";
  }
  else {
    if(count != 1) cout << "NO";
    else cout << "YES";
  }
  return 0;
}
