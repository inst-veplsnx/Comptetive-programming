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

void solution(){
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a)
        cin >> e;
    sort(all(a));
    cin >> k;
    for (int i = 0; i < k; ++i){
        int l, r;
        cin >> l >> r;
        auto it0 = lower_bound(all(a), l);
        auto it1 = upper_bound(all(a), r);
        int L = it0 - a.begin(), R = it1 - a.begin() - 1;
        cout << R - L + 1 << ' ';
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
