#include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    ll mod = 1e9 + 7;
    const int M = 1e6;
    ll n, res = 0;
    ll a[M + 5];
    bool vis[M + 1];
    ll ne[M + 1], pre[M + 1];
    struct seg
    {
        ll val, pos;
    }
    b[M + 1];
    bool cmp(seg x, seg y)
    {
        if (x.val == y.val)
            return x.pos < y.pos;
        return x.val > y.val;
    }
    void input()
    {

        cin >> n;

        a[0] = 0;
        // a[n + 1] = 0;

        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i].val = a[i];
            b[i].pos = i;
        }

        a[n + 1] = 0;

        for (ll i = 1; i <= n; i++)
        {
            pre[i] = i - 1;
            ne[i] = i + 1;
        }
        // for(ll i = 1; i <= n; i++)
        // {
        //     cout << a[i] << '\n';
        //     cout << pre[i] << " " << ne[i] << '\n';
        // }
    }
    void solve()
    {
        sort(b + 1, b + 1 + n, cmp);

        ll res = 0;

        for (int i = 1; i <= n; ++i)
        {
            int x = pre[b[i].pos], y = ne[b[i].pos];
            res += b[i].val + a[x] + a[y];
            ne[x] = y;
            pre[y] = x;
        }

        cout << res;
    }
    int main()
    {


        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);




        input();
        solve();
        return 0;
    }