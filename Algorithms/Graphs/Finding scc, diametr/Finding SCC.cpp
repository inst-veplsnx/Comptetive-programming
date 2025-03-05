#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll inf = 9e18;
const int iinf = 2e9;

void dfs(int v,vector<int>& order, vector<int>& visited, const vector<vector<int>>& g)
{
  visited[v] = 1;
  for (const int& u : g[v])
    if (visited[u] == 0)
      dfs(u, order, visited, g);
  order.push_back(v);
}

void solution()
{
  int n, k, m;
  cin >> n >> k >> m;
  vector<vector<int>> g(n);
  --k;
  for (int i = 0; i < n; ++i)
  {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
  }
  vector<int> order, visited(n, 0);
  for (int i = 0; i < n; ++i)
    if (visited[i] == 0)
      dfs(i, order, visited, g);
  reverse(order.begin(), order.end());
  if (order.front() == k)
    cout << "Yes\n";
  else
    cout << "No\n";
}

int main(/* Kurmankul Nurislam*/)
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solution();
        cout << '\n';
    }
    return 0;
}
