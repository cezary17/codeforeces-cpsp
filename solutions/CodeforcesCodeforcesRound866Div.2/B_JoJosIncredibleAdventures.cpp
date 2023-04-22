// time-limit: 1000
// problem-url: https://codeforces.com/contest/1820/problem/B
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    int len = input.size();
    if (len == 1) {
      cout << stoi(input) << endl;
      continue;
    }

    vector<vector<int>> vec(len);

    for (int j = 0; j < len; j++) {

      vec[j] = vector<int>(len);
      rotate(input.begin(), input.begin() + j, input.end());

      for (int k = 0; k < len; k++) {
        vec[j][k] = atoi(&input[k]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cout.tie(0);
  // cin >> tc;
  for (int t = 1; t <= tc; t++) {
    // cout << "Case #" << t << ": ";
    solve();
  }
}
