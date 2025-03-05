#include <bits/stdc++.h>

using namespace std;

signed main(/* Kurmankul Nurislam */)
{
    string a, b, c;
    cin >> a >> b;
    if (a.length() < b.length())
        while (a.length() < b.length())
            a = '0' + a;
    else
        while (b.length() < a.length())
            b = '0' + b;
    const int n = a.length();
    int remain = 0;
    for (int i =  n - 1; i > -1; --i)
    {
        int curr = (a[i] - '0') + (b[i] - '0');
        if (curr >= 10)
        {
            curr -= 10;
            if (10 - curr > remain)
            {
                c = char(curr + '0' + remain) + c;
                remain = 0;
            } else if (10 - curr == remain)
            {
                c = "10" + c;
                remain = 0;
            } else
            {
                c = '0' + c;
                remain -= (10 - curr);
            }
            ++remain;
        } else
        {
            if (10 - curr > remain)
            {
                c = char(curr + '0' + remain) + c;
                remain = 0;
            } else if (10 - curr == remain)
            {
                c = '0' + c;
                
            } else
            {
                c = '0' + c;
                remain -= (10 - curr);
            } 
        }
    }
    if (remain) c = char(remain + '0') + c;
    cout << c;
}
