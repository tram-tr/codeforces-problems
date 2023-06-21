// https://codeforces.com/problemset/problem/6/C

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; i++)
    cin >> t[i];
  
  int left = 0;
  int right = n-1;
  int time_a = 0;
  int time_b = 0;
  int count_a = 0;
  int count_b = 0;
  while (left <= right) {
    if (time_a <= time_b) {
      time_a += t[left];
      left++;
      count_a++;
    }
    else {
      time_b += t[right];
      right--;
      count_b++;
    }
  }
  
  cout << count_a << " " << count_b << endl;
  
  return 0;
}
