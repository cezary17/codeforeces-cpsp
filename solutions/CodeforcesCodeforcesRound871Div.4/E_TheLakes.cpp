// time-limit: 3000
// problem-url: https://codeforces.com/problemset/problem/1829/E
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <class T> ostream &operator<<(ostream &out, const vector<T> &a) {
  for (const auto &x : a) {
    out << x << " ";
  }
  out << endl;
  return out;
}
template <class T> istream &operator>>(istream &in, vector<T> &a) {
  for (auto &x : a) {
    in >> x;
  }
  return in;
}

int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis) {
  int res = grid[i][j];
  vis[i][j] = true;
  if (i > 0 && grid[i - 1][j] >= 1 && !vis[i - 1][j]) {
    res += dfs(grid, i - 1, j, vis);
  }
  if (i < grid.size() - 1 && grid[i + 1][j] >= 1 && !vis[i + 1][j]) {
    res += dfs(grid, i + 1, j, vis);
  }
  if (j > 0 && grid[i][j - 1] >= 1 && !vis[i][j - 1]) {
    res += dfs(grid, i, j - 1, vis);
  }
  if (j < grid[0].size() - 1 && grid[i][j + 1] >= 1 && !vis[i][j + 1]) {
    res += dfs(grid, i, j + 1, vis);
  }

  return res;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (auto &x : grid) {
    cin >> x;
  }

  int max = 0;
  vector<vector<bool>> vis(n, vector<bool>(m, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] || grid[i][j] == 0) {
        continue;
      }
      int curr = 0;
      curr = dfs(grid, i, j, vis);
      max = std::max(max, curr);
    }
  }
  cout << max << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    // cout << "Case #" << t << ": ";
    solve();
  }
}
