// https://codeforces.com/problemset/problem/448/B

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  string s, t;
  cin >> s >> t;
 
  string sorts = s;
  string sortt = t;
  sort(sorts.begin(), sorts.end());
  sort(sortt.begin(), sortt.end());
  bool is_array = (sorts == sortt);
  
  size_t count = 0;
  for (size_t i = 0; i < s.length() && count < t.length(); i++) {
  	if (s[i] == t[count]) count++;
  }
  bool is_automaton = (count == t.length());
  
  string visited = s;
 	bool is_both = true;
  for (size_t i = 0; i < t.length(); i++) {
  	size_t idx = visited.find(t[i]);
    if (idx != -1)
    	visited[idx] = '1';
     else {
     	is_both = false;
      break;
     }
  }
  
  if (is_array)
  	cout << "array";
  else if (is_automaton)
  	cout << "automaton";
  else if (is_both)
  	cout << "both";
  else
  	cout << "need tree";
}
