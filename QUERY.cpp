#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll test;
void solve(){
	ll quer, mod;
	ll x = 1;
	ll a[100005];
	cin>>quer>>mod;
	ll c, val;
	ll attem;
	for(int i = 1; i <= quer; i++){
		cin>>c>>val;
		if(c == 1){
			x = ((x % mod) * (val % mod)) % mod;
			a[i] = val;
		}
		if(c == 2){
			x= (x % mod) * (a[val] % mod) % mod;

		}
		cout<<x % mod<<endl;
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>test;
	while(test--){
		solve();
	}
}
