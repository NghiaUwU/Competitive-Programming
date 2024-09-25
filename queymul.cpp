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
        st[index] = k;
        // cout<< "update "<< index << " " << k << '\n';
        return;
    }

    ll mid = (l + r) / 2;
    update(index * 2, l, mid, i, k);
    update(index * 2 + 1, mid + 1, r, i, k);
    st[index] = st[index * 2] * st[index * 2 + 1] % q;
}

ll tich(ll index, ll l, ll r, ll u, ll v)
{
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return st[index];

    ll mid = (l + r) / 2;
    return tich(index * 2, l, mid, u, v) * tich(index * 2 + 1, mid + 1, r, u, v) % q;
}

void solve()
{
    cin >> m >> q;
    st.assign(4 * m + 1, 1);
    a.resize(m + 1);

    for (ll i = 1; i <= m; i++)
    {
        ll t, j;
        cin >> t >> j;
        if (t == 1)
        {
            //a[i]=j;
            update(1, 1, m, i, j);
            cout << tich(1, 1, m, 1, m) << '\n';
        }
        else
        {
           
            update(1, 1, m, j, 1);
            cout << tich(1, 1, m, 1, m) << '\n';
        }
        a[i]=j;
    }
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

    ll n;
    cin>>n;

    
    while(n--)
    {
        solve();
        //for(ll i=1;i<=4*m;i++) st[i]=1; 
    }
    return 0;
}
