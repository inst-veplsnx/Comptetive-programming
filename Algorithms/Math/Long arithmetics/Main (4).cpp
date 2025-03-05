#include <bits/stdc++.h>

using namespace std;

typedef complex<double> Complex;
typedef vector<Complex> CVector;

const long double PI = 3.14159265358979323846;

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

void fft(CVector &a, bool invert)
{
    int n = a.size();
    if (n == 1) 
        return;
    CVector a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++)
    {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);
    double angle = 2 * PI / n * (invert ? -1 : 1);
    Complex w(1), wn(cos(angle), sin(angle));
    for (int i = 0; 2 * i < n; i++)
    {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) 
        {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

string multiply(const string &a, const string &b)
{
    vector<int> num1, num2;
    for (char c : a) num1.push_back(c - '0');
    for (char c : b) num2.push_back(c - '0');
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int n = 1;
    while (n < num1.size() + num2.size()) n *= 2;
    CVector fa(num1.begin(), num1.end()), fb(num2.begin(), num2.end());
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) 
        fa[i] *= fb[i];
    fft(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++) 
        result[i] = round(fa[i].real());

    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
    while (result.size() > 1 && result.back() == 0) result.pop_back();
    string res;
    for (auto it = result.rbegin(); it != result.rend(); ++it) 
        res += *it + '0';
    return res;
}

signed main()
{
    cin.tie(nullptr) -> sync_with_stdio(false);
    string current = "1", target;
    string n = "1";
    cin >> target;
    while (current != target)
    {
        n = addStrings(n, "1");
        current = multiply(current, n);
    }
    cout << n;
}
    