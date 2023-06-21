// https://codeforces.com/problemset/problem/892/B

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  int claws[n];
  for (int i = 0; i < n; i++) 
    cin >> claws[i];
  
  int alive[n];
  for (int i = 0; i < n; i++)
    alive[i] = 1;
  
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i - 1; j >= i - claws[i] && j >= 0; j--)
      alive[j] = 0;
  }
  
  int total = 0;
  for (int i = 0; i < n; i++)
    total += alive[i];
  
  cout << total;
  
  return 0;
}
