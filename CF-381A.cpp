//https://codeforces.com/contest/381/problem/A

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n; 
  cin >> n;
  int cards[n];
  
  for (int i = 0; i < n; i++)
    cin >> cards[i];
  
  int left = 0;
  int right = n-1;
  int odd_score = 0;
  int even_score = 0;
  int turns = n;
  
  while (turns > 0 && left <= right) {
    int picked = 0;
    if (cards[left] < cards[right]) {
      picked = cards[right];
      right--;
    }
    else {
      picked = cards[left];
      left++;
    }
		if (turns % 2 == 0)
      even_score += picked;
    else 
      odd_score += picked;
    turns--;
  }
  
  if (n % 2 == 0)
    cout << even_score << " " << odd_score << endl;
  else
    cout << odd_score << " " << even_score << endl;
  
  return 0;
}
