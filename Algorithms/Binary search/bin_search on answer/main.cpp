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

int cnt(long double x, const vector<long double>& a){
    int res = 0;
    int n = sz(a);
    for (int i = 0; i < n; ++i)
        res += (int)a[i] / x;
    return res;
}

void solution(){
    int n, k;
    cin >> n >> k;
    vector<long double> a(n);
    for (auto& e : a)
        cin >> e;
    long double l = 0, r = 1e7;
    for (int i = 0; i < 100; ++i){
        long double m = (l + r) / 2;
        if (cnt(m, a) >= k)
            l = m;
        else
            r = m;
    }
    cout << fixed << setprecision(12) << (l + r) / 2;
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
