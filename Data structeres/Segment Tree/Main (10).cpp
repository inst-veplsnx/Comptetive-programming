#include <bits/stdc++.h>

using namespace std;

class segmentTree
{
public:
    vector<int64_t> nodes;
    int size = 1;
    segmentTree(vector<int>& a)
    {
        const int n = a.size();
        while (size < n) size <<= 1;
        nodes.assign(2 * size, 0);
        for (int i = 0; i < n; ++i)
            nodes[i + size] = a[i];
        for (int i = size - 1; i > 0; --i)
            nodes[i] = nodes[2 * i] + nodes[2 * i + 1];
    }
    
    void update(int x, int pos)
    {
        nodes[pos += size] = x;
        for (int i = pos / 2; i > 0; i /= 2)
            nodes[i] = nodes[2 * i] + nodes[2 * i + 1];
    }
    
    int64_t query(int l, int r)
    {
        l += size; r += size;
        int64_t res = 0;
        while (l <= r)
        {
            if (l % 2 == 1) res += nodes[l++];
            if (r % 2 == 0) res += nodes[r--];
            l /= 2; r /= 2;
        }
        return res;
    }    
};

signed main(/* Kurmankul Nurislam */)
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a)
        cin >> e;
    segmentTree sgt(a);
    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << sgt.query(l - 1, r - 1) << ' ';
    }
}
