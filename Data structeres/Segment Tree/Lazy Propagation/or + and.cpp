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
    vector<ll> t, l;
    void build(int v, int tl, int tr, const vector<int>& a){
        if (tl == tr){
            t[v] = a[tl];
            return;
        }
        int tm = tl + tr >> 1;
        build(2 * v + 1, tl, tm, a);
        build(2 * v + 2, tm + 1, tr, a);
        t[v] = t[2 * v + 1] & t[2 * v + 2];
    }
    void push(int v){
        if (l[v] != 0){
            l[2 * v + 1] |= l[v];
            l[2 * v + 2] |= l[v];
            t[2 * v + 1] |= l[v];
            t[2 * v + 2] |= l[v];
            l[v] = 0;
        }
    }
    void upd(int v, int tl, int tr, int ql, int qr, int d){
        if (ql > tr || qr < tl)
            return;
        if (ql <= tl && tr <= qr){
            t[v] |= d; 
            l[v] |= d;
            return;
        }
        push(v);
        int tm = tl + tr >> 1;
        upd(2 * v + 1, tl, tm, ql, qr, d);
        upd(2 * v + 2, tm + 1, tr, ql, qr, d);
        t[v] = t[2 * v + 1] & t[2 * v + 2];
    }
    ll get(int v, int tl, int tr, int ql, int qr){
        if (ql > tr || qr < tl)
            return (1 << 30) - 1;
        if (ql <= tl && tr <= qr)
            return t[v];
        push(v);
        int tm = tl + tr >> 1;
        return get(2 * v + 1, tl, tm, ql, qr) & get(2 * v + 2, tm + 1, tr, ql, qr);
    }
public:
    SegmentTree(const vector<int>& a, const int size){
        n = size;
        t.resize(4 * n);
        l.assign(4 * n, 0);
        build(0, 0, n - 1, a);
    }
    void upd(int ql, int qr, int m){
        return upd(0, 0, n - 1, ql, qr, m);
    }
    int get(int ql, int qr){
        return get(0, 0, n - 1, ql, qr);
    }
};

void solution(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    SegmentTree sgt(a, n);
    while (q--){
        int t;
        cin >> t;
        if (t == 1){
            int l, r, v;
            cin >> l >> r >> v;
            sgt.upd(l, r - 1, v);
        } else{
            int l, r;
            cin >> l >> r;
            cout << sgt.get(l, r - 1) << '\n';
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
