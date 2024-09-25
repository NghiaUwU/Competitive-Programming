#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;
struct SEG{
	ll g, l, r, sum;
};
vector <SEG> smt;
vector <ll> a;
void build(int index = 1, int l = 1, int r = n){
	if(l == r){
		smt[index].g = max(a[l], LLONG_MIN);
		smt[index].l = max(a[l], LLONG_MIN);
		smt[index].r = max(a[l], LLONG_MIN);
		smt[index].sum = max(a[l], LLONG_MIN);
	}
	else{
		ll mid = (l + r) / 2;
		build(index * 2, l, mid);
		build(index * 2 + 1, mid + 1, r);
		//=================================//
		smt[index].g = max(max(smt[index * 2].g, smt[index * 2 + 1].g), smt[index * 2].r + smt[index * 2 + 1].l);
		smt[index].l = max(smt[index * 2].l, smt[index * 2].sum + smt[index * 2 + 1].l);
		smt[index].r = max(smt[index * 2 + 1].r, smt[index * 2 + 1].sum + smt[index * 2].r);
		smt[index].sum = smt[index * 2].sum + smt[index * 2 + 1].sum;
		//=================================//
	}
}
void update(ll index, ll l, ll r, ll i, ll k){
	if(l == r){
		smt[index].g = max(k, LLONG_MIN);
		smt[index].l = max(k, LLONG_MIN);
		smt[index].r = max(k, LLONG_MIN);
		smt[index].sum = max(k, LLONG_MIN);
	}
	else{
		ll mid = (l + r) / 2;
		if(i > mid)	update(index * 2 + 1, mid + 1, r, i, k);
		else	update(index * 2, l, mid, i, k);
		//================================//
		smt[index].g = max(max(smt[index * 2].g, smt[index * 2 + 1].g), smt[index * 2].r + smt[index * 2 + 1].l);
		smt[index].l = max(smt[index * 2].l, smt[index * 2].sum + smt[index * 2 + 1].l);
		smt[index].r = max(smt[index * 2 + 1].r, smt[index * 2 + 1].sum + smt[index * 2].r);
		smt[index].sum = smt[index * 2].sum + smt[index * 2 + 1].sum;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	smt.resize(4 * n + 2);
	a.resize(n + 2);
	
	
	for(int i = 1; i <= n; i++)	cin>>a[i];
	build();
	while(m--){
		int x, y;
		cin>>x>>y;
		update(1, 1, n, x, y);
		cout<<smt[1].g<<" ";
	}
}
