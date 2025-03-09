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

bool check(ll t, int x, int y, int n){
    if (t < x)
        return false;
    return 1 + (t - x) / x + (t - x) / y >= n;
}

void solution(){
    int n, x, y;
    cin >> n >> x >> y;
    if (x > y)
        swap(x, y);
    ll low = 0, high = 1e12;
    while (high - low > 1){
        ll middle = high + low >> 1;
        if (check(middle, x, y, n))
            high = middle;
        else
            low = middle;
    }
    cout << low + 1;
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
