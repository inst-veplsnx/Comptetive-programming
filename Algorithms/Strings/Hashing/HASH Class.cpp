#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct HASH
{
    const int MOD1 = 1000000007;
    const int MOD2 = 1000000009;
    const int BASE = 911382629;
    int n;
    vector<ll> power1, power2;
    vector<ll> hash1, hash2;
    HASH(const string& s)
    {
        n = s.length();
        power1.assign(n + 1, 1);
        power2.assign(n + 1, 1);
        hash1.assign(n + 1, 1);
        hash2.assign(n + 1, 1);
        for (int i = 0; i < n; ++i)
        {
            power1[i + 1] = (power1[i] * BASE) % MOD1;
            power2[i + 1] = (power2[i] * BASE) % MOD2;
            hash1[i + 1] = (hash1[i] * BASE + s[i]) % MOD1;
            hash2[i + 1] = (hash2[i] * BASE + s[i]) % MOD2;
        }
    }
    pair<ll, ll> get_hash(const int& l, const int& r)
    {
        ll res1 = (hash1[r] - hash1[l] * power1[r - l]) % MOD1;
        if (res1 < 0)
            res1 += MOD1;
        ll res2 = (hash2[r] - hash2[l] * power2[r - l]) % MOD2;
        if (res2 < 0) 
            res2 += MOD2;
        return {res1, res2};
    }
};

signed main()
{
    cin.tie(nullptr) -> sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    const int n = a.length(), m = b.length();
    if (n != m)
    {
        cout << "No";
        exit(0);
    }
    string reversed_a = a;
    reverse(reversed_a.begin(), reversed_a.end());
    HASH ha(a);
    HASH har(reversed_a);
    HASH hb(b);
    for (int k = 0; k <= n; ++k)
    {
        bool ok = true;
        if (k > 0)
        {
            if (k > n)
                ok = false;
            else
            {
                pair<ll, ll> hash_pref_a = har.get_hash(n - k, n);
                pair<ll, ll> hash_suff_b = hb.get_hash(n - k, n);
                if (hash_pref_a != hash_suff_b)
                    ok = false;
            }
        }
        if (n - k > 0)
        {
            if (n - k > n)
                ok = false;
            else
            {
                pair<ll, ll> hash_suff_a = ha.get_hash(k, n);
                pair<ll, ll> hash_pref_b = hb.get_hash(0, n - k);
                if (hash_suff_a != hash_pref_b)
                    ok = false;
            }
        }
        if (ok)
        {
            cout << "Yes\n" << k;
            exit(0);
        }
    }
    cout << "No\n";
}
