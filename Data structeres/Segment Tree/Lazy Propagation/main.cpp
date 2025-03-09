/*
q:
    1: l, r, v do a[i] = v, l <= i < r
    2: i print a[i] value
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define u128 unsigned __int128
#define i128 __int128
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define ff first
#define ss second

const ll inf = 9e18;
const int iinf = 2e9;
const int N = 1e5;
const ll MOD = 1e9 + 7;

class SegmentTree{
private:
    int n;
    vector<int> t, l;
    void build(int v, int tl, int tr, const vector<int>& a){
        if (tl == tr){
            t[v] = a[tl];
            return;
        }
        int tm = tl + tr >> 1;
        build(2 * v + 1, tl, tm, a);
        build(2 * v + 2, tm + 1, tr, a);
    }
    void push(int v){
        if (l[v] != -1){
            l[2 * v + 1] = l[v];
            l[2 * v + 2] = l[v];
            t[2 * v + 1] = l[v];
            t[2 * v + 2] = l[v];
            l[v] = -1;
        }
    }
    void upd(int v, int tl, int tr, int ql, int qr, int d){
        if (ql > tr || qr < tl)
            return;
        if (ql <= tl && tr <= qr){
            l[v] = d;
            t[v] = d;
            return;
        }
        int tm = tl + tr >> 1;
        push(v);
        upd(2 * v + 1, tl, tm, ql, qr, d);
        upd(2 * v + 2, tm + 1, tr, ql, qr, d);
    }
    int get(int v, int tl, int tr, int i){
        if (tl == tr)
            return t[v];
        push(v);
        int tm = tl + tr >> 1;
        if (i <= tm)
            return get(2 * v + 1, tl, tm, i);
        else
            return get(2 * v + 2, tm + 1, tr, i);
    }
public:
    SegmentTree(const int size, const vector<int>& a){
        n = size;
        t.assign(4 * n, 0);
        l.assign(4 * n, -1);
        build(0, 0, n - 1, a);
    }
    void upd(int ql, int qr, int d){
        upd(0, 0, n - 1, ql, qr, d);
    }
    int get(int i){
        return get(0, 0, n - 1, i);
    }
};

void solution(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    SegmentTree sgt(n, a);
    while (q--){
        int t;
        cin >> t;
        if (t == 1){
            int l, r, d;
            cin >> l >> r >> d;
            sgt.upd(l, r - 1, d);
        } else{
            int i;
            cin >> i;
            cout << sgt.get(i) << '\n';
        }
    }
}

signed main(/* Kurmankul Nurislam */){
    //freopen("fcolor.in", "r", stdin);
    //freopen("fcolor.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--){
        solution();
        //cout << '\n';
    }
}
