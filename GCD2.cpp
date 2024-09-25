#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M=1e9+7;
vector<ll> st, a;
map<int, vector<int>> d;
void update(ll index, ll l, ll r, ll i, ll k)
{
    if (i < l  r < i)
        return;
    if (l == r)
    {
        st[index] = k;
        return;
    }

    ll mid = (l + r) / 2;
    update(index * 2, l, mid, i, k);
    update(index * 2 + 1, mid + 1, r, i, k);
    st[index] = __gcd( st[index * 2],  st[index * 2 + 1] ) ;
}

ll gcd(ll index, ll l, ll r, ll u, ll v)
{
    if (v < l  r < u)
        return 0;
    if (u <= l && r <= v)
        return st[index];

    ll mid = (l + r) / 2;
    return __gcd( gcd(index * 2, l, mid, u, v) , gcd(index * 2 + 1, mid + 1, r, u, v)) ;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
	ll q;
    cin>>q;

    ll n=1e5;
    st.assign(4 * n + 1, 0);
    a.resize(n + 1);

    for(ll i=1;i<=q;i++)
    {
        ll t,j;
        cin >> t >> j;
        if( t == 1 )
        {
            update(1, 1, n, i, j);
            cout << gcd(1, 1, n, 1, n)<<'\n';
            a[i]=j;
            d[j].push_back(i);
        }
        else
        { 
            ll x = d[j].back();
            update(1, 1, n, x, 0);
            d[j].pop_back();
            ll res = gcd(1, 1, n, 1, n);
            if(res==0) res=1;
            cout<<res<<'\n';
        }
    }
    return 0;
}
