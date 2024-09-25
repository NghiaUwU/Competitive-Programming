#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M = 1e9 + 7;
vector<ll> st, a;
ll m, q;

void update(ll index, ll l, ll r, ll i, ll k)
{
    if (i < l || r < i)
        return;
    if (l == r)
    {
        st[index] += k;
        return;
    }

    ll mid = (l + r) / 2;
    update(index * 2, l, mid, i, k);
    update(index * 2 + 1, mid + 1, r, i, k);
    st[index] = st[index * 2] + st[index * 2 + 1];
}

ll tong(ll index, ll l, ll r, ll u, ll v)
{
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return st[index];

    ll mid = (l + r) / 2;
    return tong(index * 2, l, mid, u, v) + tong(index * 2 + 1, mid + 1, r, u, v);
}

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

    ll n, q;
    cin >> n >> q;
    st.assign(4 * n + 1, 0);
    a.resize(n + 1);
    for(ll i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        update(1, 1, n, i, x);
    }
    //cout << tong(1, 1, n, 1, n) << '\n';
    while(q--)
    {
        ll j;
        cin>>j;
        if (j == 1)
        {
            ll u, v, k;
            cin >> u >> v ;
            update(1, 1, n, u, v);
        
        }

        else
        {
            ll u, v;
            cin >> u >> v;
            cout << tong(1, 1, n, u, v) << '\n';
        }
    }
    return 0;
}
