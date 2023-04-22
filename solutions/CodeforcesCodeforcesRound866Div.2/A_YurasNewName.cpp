// time-limit: 1000
// problem-url: https://codeforces.com/contest/1820/problem/A
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {

    string s;
    cin >> s;
    char last = s[0];
    char curr = s[0];
    int counter = s[0] == '^' && s.size() != 1 ? 0 : 1;

    for (int j = 1; j < s.size(); j++) {
      curr = s[j];
      if (curr == '_' && last == '_') {
        counter++;
      }
      last = curr;
    }
    if (curr == '_') {
      counter++;
    };
    cout << counter << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; t++) {
    // cout << "Case #" << t << ": ";
    solve();
  }
}
