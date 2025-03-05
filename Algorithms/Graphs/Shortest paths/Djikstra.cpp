#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 1;

struct Edge
{
  int to, weight;
};

vector<int> djikstra(int start, const vector<vector<Edge>>& graph, const int& n)
{
  vector<int> dst(n, INF);
  dst[start] = 0;
  priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
  pq.push(make_tuple(0, start));
  while (!pq.empty())
  {
    int curr_dst, u;
    tie(curr_dst, u) = pq.top();
    pq.pop();
    if (curr_dst > dst[u])
      continue;
    for (const Edge& edge : graph[u])
    {
      int v = edge.to, weight = edge.weight;
      if (dst[v] > curr_dst + weight)
      {
        dst[v] = curr_dst + weight;
        pq.push(make_tuple(dst[v], v));
      }
    }
  }
  return dst;
}

signed main(/* Kurmankul Nurislam */) 
{
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i)
    {
      int a, b, weight;
      cin >> a >> b >> weight;
      graph[a].push_back({b, weight});
      graph[b].push_back({a, weight});
    }
    vector<int> dst = djikstra(0, graph, n);
    for (int i = 0; i < n; ++i)
      cout << dst[i] << '\n';
    
}
