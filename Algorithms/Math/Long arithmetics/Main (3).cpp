#include <bits/stdc++.h>

using namespace std;
using cd = complex<double>;

const long double PI = acos(-1);

string addStrings(const string &a, const string &b)
{
    string result;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result += (sum % 10) + '0';
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double angle = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(angle), sin(angle));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    int carry = 0;
    for (int i = 0; i < n; i++) {
        result[i] = int(round(fa[i].real())) + carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
    while (!result.empty() && result.back() == 0) result.pop_back();
    return result;
}

vector<int> stringToVector(const string& s) {
    vector<int> result(s.size());
    for (int i = 0; i < s.size(); i++) {
        result[s.size() - i - 1] = s[i] - '0';
    }
    return result;
}

string vectorToString(const vector<int>& v) {
    string result;
    for (int i = v.size() - 1; i >= 0; i--) {
        result += (v[i] + '0');
    }
    return result.empty() ? "0" : result;
}

vector<int> subtract(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        int sub = a[i] - carry - (i < b.size() ? b[i] : 0);
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(sub);
    }
    while (result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}

string divide(const string& num1, const string& num2) {
    vector<int> a = stringToVector(num1);
    vector<int> b = stringToVector(num2);

    if (b.size() == 1 && b[0] == 0) throw invalid_argument("Division by zero");

    vector<int> quotient, current;
    current.reserve(a.size());

    for (int i = a.size() - 1; i >= 0; i--) {
        current.insert(current.begin(), a[i]);
        while (!current.empty() && current.back() == 0) current.pop_back();

        int x = 0, l = 0, r = 10;
        while (l <= r) {
            int m = (l + r) / 2;
            vector<int> product = multiply(b, {m});
            if (product.size() > current.size() || (product.size() == current.size() && product > current)) {
                r = m - 1;
            } else {
                x = m;
                l = m + 1;
            }
        }

        quotient.push_back(x);
        vector<int> product = multiply(b, {x});
        current = subtract(current, product);
    }

    reverse(quotient.begin(), quotient.end());
    while (!quotient.empty() && quotient.back() == 0) quotient.pop_back();

    return quotient.empty() ? "0" : vectorToString(quotient);
}

signed main()
{
    cin.tie(nullptr) -> sync_with_stdio(false);
    const string target = "1";
    string n = "1";
    string current;
    cin >> current;
    while (current != "1")
    {
        n = addStrings(n, "1");
        current = divide(current, n);
    }
    cout << n;
}
