#include <bits/stdc++.h>
using namespace std;

int n, q;
vector <int> tp1, tp2; 
int pos[100005];
void update1(int index, int l, int r, int i, int k){
	if(i < l || r < i)	 return;
	if(l == r){
		tp1[index] = k;
		return;
	}
	int mid = (l + r) / 2;
	update1(index * 2, l, mid, i, k);
	update1(index * 2 + 1, mid + 1, r, i, k);
	tp1[index] = min(tp1[index * 2], tp1[index * 2 + 1]);
}
void update2(int index, int l, int r, int i, int k){
	if(i < l || r < i)	 return;
	if(l == r){
		tp2[index] = k;
		return;
	}
	int mid = (l + r) / 2;
	update2(index * 2, l, mid, i, k);
	update2(index * 2 + 1, mid + 1, r, i, k);
	tp2[index] = min(tp2[index * 2], tp2[index * 2 + 1]);
}
int ask1(int x, int l, int r, int u, int v){
	if(u > r || l > v)	return 1e9;
	if(l >= u && r <= v)	return tp1[x];
	int mid = (l + r) / 2;
	return  min(ask1(x * 2, l, mid, u, v), ask1(x * 2 + 1, mid + 1, r, u, v));
}
int ask2(int x, int l, int r, int u, int v){
	if(u > r || l > v)	return 1e9;
	if(l >= u && r <= v)	return tp2[x];
	int mid = (l + r) / 2;
	return min(ask2(x * 2, l, mid, u,v), ask2(x * 2  + 1, mid + 1, r, u, v));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>q;
	for(int i = 1; i <= n; i++){int x, y; cin>>x>>y;}
	while(q--){
		int c, u;
		cin>>c;
		if(c == 1){
			cin>>u>>pos[u];
			update1(1, 1, n, u, pos[u] - u);
			update2(1, 1, n, u, pos[u] + u);
		}
		if(c == 2){
			cin>>u;
			cout<<min(u - 1, min(ask1(1, 1, n, 1, u) + u, ask2(1, 1, n, u + 1, n) - u))<<endl;
		}
	}
}
