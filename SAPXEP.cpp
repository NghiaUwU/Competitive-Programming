#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <ll> a, pre, suf;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	long long sum = 0;
	cin>>n;
	a.resize(n + 1);
	pre.resize(n + 1);
	suf.resize(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1;  i<= n; i++){
		pre[i] = max(pre[i - 1], a[i]);
	}
	suf[n + 1] = 1e18;
	for(int i = n; i >= 1; i--){
		suf[i] = min(suf[i + 1], a[i]);
	}
	int ans = 1;
	for(int i = 1; i <= n; i++){
		if(pre[i] <= suf[i])	ans++;
	}
	cout<<ans;
}
