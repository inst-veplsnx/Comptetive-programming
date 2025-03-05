#include <bits/stdc++.h>

#define ll long long

using namespace std;

signed main()
{
    cin.tie(nullptr) -> sync_with_stdio(false);
    string current = "1";
    string target;
    cin >> target;
    int i = 1;
    while (current != target)
    {
        ++i;
        string c = "";
        ll carry = 0, temp;
        for (int k = current.size() - 1; k > -1; --k)
        {
            temp = (current[k] - '0') * i + carry;
            carry = temp / 10;
            c = char(temp % 10 + '0') + c;
        }
        while (carry)
        {
            c = char(carry % 10 + '0') + c;
            carry /= 10;
        }
        current = c;
    }
    cout << i;
}
