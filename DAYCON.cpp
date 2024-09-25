	#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//you get it?//
vector <int> a, st;

void update(ll index, ll l, ll r, ll i, ll k )
{
    if (i < l || r < i)
        return;
    if (l == r)
    {
        st[index] = k;
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


// update for saving
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;
	cin>>n;
	st.assign(4 * n + 1, 0);
	a.assign(n + 1 ,0);
	vector <int> dp(n + 1, 0);
	dp[0] = 0;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	
	for(int i = 1;  i <= n; i++){
		if(a[i] > 0){
			dp[i] = tmx(1, 1, 1000006, 0, a[i] - 1) + 1;
			update(1, 0, 1000006, a[i], dp[i]);
		}
		else{
			dp[i] = 1;
			update(1, 0, 1000006, a[i], 1);
		}
	}
	
	int ans = 0;
    for(int i = 1; i <= n; ++ i)
        ans = max(dp[i], ans);
    cout << ans;
	
}
