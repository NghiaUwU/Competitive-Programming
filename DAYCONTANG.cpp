#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <int> st, a, power;
vector <int> dp, pos;
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	st.resize(4 * n + 2);
	a.resize(n + 2);
	power.resize(n + 2);
	dp.resize(n + 2);
	pos.resize(n + 2);
	dp[0] = 0;
	pos[0] = 0;
	
	for(int i = 1; i <= n; i++)	cin>>a[i];
	for(int i = 1; i <= n; i++)	cin>>power[i];
	
	for(int i = 1; i <= n; i++){
		if(a[i] > pos[i - 1]){
			dp[i] = tmx(1, 1, 1000006, 0, power[i] - 1) + 1;
			update(1, 0, 1000006, power[i], dp[i]);
			pos[i] = a[i];
		}
		else{
			dp[i] = 1;
			update(1, 0, 1000006, a[i], 1);
			pos[i] = a[i];
		}
	}
	int ans = 0;
    for(int i = 1; i <= n; ++ i)
        ans = max(dp[i], ans);
    cout << ans;
	
	
	
}
