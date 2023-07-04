// https://codeforces.com/problemset/problem/518/A

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string s, t;
  cin >> s >> t;
  string temp = t;
  for (int i = t.length()-1; i >= 0; i--) {
    if (temp[i] == 'a')
      	temp[i] = 'z';
   	else {
      temp[i]--;
      break;
    }
  }
  if (temp != s)
    cout << temp;
 	else
    cout << "No such string";
  
  return 0;
}
