#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5;
ll fact[N + 1], ifact[N + 1];

ll fpow(ll x, ll y)
{
    if (y == 0) return 1ll;
    if (y == 1) return x % MOD;
    if (y & 1)
        return x * fpow(x, y - 1) % MOD;
    ll sqr = fpow(x, y / 2);
    return sqr * sqr % MOD;
}

ll C(const ll& n, const ll& k)
{
    if (k < 0 || k > n) return 0ll; 
    return (((fact[n] * ifact[k]) % MOD) * ifact[n - k]) % MOD;
}

signed main(/* Kurmankul Nurislam */)
{
    cin.tie(nullptr) -> sync_with_stdio(false);
    fact[0] = 1;
    for (ll i = 1; i <= N; ++i)
        fact[i] = (fact[i - 1] * i) % MOD;
    ifact[N] = fpow(fact[N], MOD - 2);
    for (ll i = N - 1; i > -1; --i)
        ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
    int n = 4, k = 2;
    cout << C(n, k);
}
