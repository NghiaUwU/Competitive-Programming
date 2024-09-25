#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define cerr cout
ll read(){ll n; cin>>n; return n;}
str readstr(){str s; cin>>s; return s;}
vector <ll> h, d, u, dp;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int res = 0;	
	ll n = read();
	h.resize(n + 2);
	d.resize(n + 2);
	u.resize(n + 2);
	dp.assign(n + 2, 1e9);
	dp[0] = -1;
	
	for(int i = 1; i <= n; i++)	cin>>h[i];
	for(int i = 1; i <= n; i++){
		cin>>d[i];
		u[i] = d[i] + h[i];
	}
	for(int i = 1; i <= n; i++){
		int l = 0, r = n;
		int len = 0;
		while(l <= r){
			int mid = (l + r) / 2;
			if(dp[mid] > h[i]){
				r = mid - 1;
			}
			if(dp[mid] <= h[i]){
				l = mid + 1;
				len = max(len, mid);
			}
		}
		 dp[len + 1] = min(dp[len+1],u[i]);
		res = max(res, len + 1);	
	}
	cerr << res;
	
}
