// https://codeforces.com/problemset/problem/721/B

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k;
  cin >> n >> k;
  
  vector<string> pwd(n);
  for (int i = 0; i < n; i++)
    cin >> pwd[i];
  
  string codehorses;
  cin >> codehorses;
  
  int shorter = 0;
  int longer = 0;
  for (int i = 0; i < n; i++) {
    if (pwd[i].length() < codehorses.length())
      shorter++;
    else if (pwd[i].length() > codehorses.length())
      longer++;
  }
  
  int min_time = shorter + (shorter / k * 5) + 1;
  int max_time = (n - longer - 1) + ((n - longer - 1) / k * 5) + 1;
  
  cout << min_time << " " << max_time << endl;
  
  return 0;
}
