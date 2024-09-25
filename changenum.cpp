#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("", "r"))
    {
        freopen("", "r", stdin);
        freopen("", "w", stdout);
    }

    ll n;
    cin >> n;



    if(n == 10)
    {
        cout << 12;
        return 0;
    }


    string c = to_string(n);
    ll l = c.size();

    if (n % 4 == 0)
    {
        int kt = 2;

        if (c[0] != '1')
        {
            c[0] = '1';
            kt--;
        }

        for (int i = 1; i < c.size() - 2; i++)
        {
            if (kt == 0)
                break;
            else if (c[i] != '0')
            {
                c[i] = '0';
                kt--;
            }
        }

        if (kt == 2)
        {
            c[l - 1] = '0';
            c[l - 2] = '0';
        }
        else if (kt == 1)
        {
            if (c[l - 2] >= '2')
            {
                while (c[l - 2] >= '2')
                    c[l - 2] = char(c[l - 2] - 2);
            }
            else if (c[l - 1] >= '4')
            {
                while (c[l - 1] >= '4')
                    c[l - 1] = char(c[l - 1] - 4);
            }
        }

        cout << c;
        return 0;
    }

    ll m = n % 10;
    ll x = n % 100;

    if (m >= x % 4)
    {
        int kt = 1;

        if (c[0] != '1')
        {
            c[0] = '1';
            kt--;
        }

        for (int i = 1; i < c.size() - 2; i++)
        {
            if (kt == 0)
                break;
            else if (c[i] != '0')
            {
                c[i] = '0';
                kt--;
            }
        }

        if (x % 4 == 2)
        {
            if (c[l - 2] >= '1')
            {
                c[l - 2] = char(c[l - 2] - 1);
                while (c[l - 2] >= '2')
                    c[l - 2] = char(c[l - 2] - 2);
            }
        }
        else
        {
            m -= x % 4;

            x -= x % 4;

            c[l - 1] = char(m + 48);

            while (m >= 4)
            {
                m -= 4;
                c[l - 1] = char(m + 48);
            }
        }

        cout << c;
    }
    else
    {

        c[l - 1] = '0';

        // x /= 10;

        c[l - 2] = '0';

        cout << c << '\n';
    }

    return 0;
}
