#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, u, v, k, q;
vector<ll> st, a;
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
    st[index] = max( st[index * 2],  st[index * 2 + 1] ) ;
}

ll tmx(ll index, ll l, ll r, ll u, ll v)
{
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return st[index];

    ll mid = (l + r) / 2;
    return max(tmx(index * 2, l, mid, u, v) ,tmx(index * 2 + 1, mid + 1, r, u, v));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	st.assign(4 * n + 2, 0);
    a.assign(n + 2, 0);
	for(int i = 1; i <= m; i++){
		cin>>u>>v>>k;
		a[u] += k;
		a[v + 1] -= k;
	}
	for(int i = 1; i <= n; i++){
		a[i] += a[i - 1];
	}
	for(int i = 1; i <= n; i++){
		update(1, 1, n, i, a[i]);
	}
	cin>>q;
	while(q--){
		cin>>u>>v;
		cout<<tmx(1,1,n,u,v)<<endl;
	}
	
}
