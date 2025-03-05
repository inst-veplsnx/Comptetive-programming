#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addStrings(const string &a, const string &b)
{
    string result;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result += (sum % 10) + '0';
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string subtractStrings(const string &a, const string &b) {
    string result;
    int borrow = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0) {
        int sub = (a[i] - '0') - (j >= 0 ? (b[j--] - '0') : 0) - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += sub + '0';
        i--;
    }
    reverse(result.begin(), result.end());
    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

string multiply(const string &a, const string &b) {
    if (a.size() == 1 && b.size() == 1) {
        return to_string((a[0] - '0') * (b[0] - '0'));
    }

    int n = max(a.size(), b.size());
    if (n % 2 != 0) n++;  
    string a_padded = string(n - a.size(), '0') + a;
    string b_padded = string(n - b.size(), '0') + b;

    int half = n / 2;
    string a1 = a_padded.substr(0, half);
    string a0 = a_padded.substr(half);
    string b1 = b_padded.substr(0, half);
    string b0 = b_padded.substr(half);

    string z2 = multiply(a1, b1);
    string z0 = multiply(a0, b0);
    string z1 = multiply(addStrings(a1, a0), addStrings(b1, b0));
    z1 = subtractStrings(subtractStrings(z1, z2), z0);

    z2 += string(2 * half, '0');
    z1 += string(half, '0');

    string result = addStrings(addStrings(z2, z1), z0);
    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

signed main()
{
    cin.tie(nullptr) -> sync_with_stdio(false);
    string target;
    cin >> target;
    string current = "1", n = "1";
    while (current != target)
    {
        n = addStrings(n, "1");
        current = multiply(current, n);
    }
    cout << n;
}
    
