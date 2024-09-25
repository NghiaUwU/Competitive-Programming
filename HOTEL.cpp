#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;
vector <ll> hotel, ram; 
vector <ll> st;
void update(int index, int l, int r, int i, int k){
	if(i < l || r < i)	return;
	if(l == r){
		st[index] = k;
		return;
	}
	int mid = (l + r) / 2;
	update(index * 2, l, mid, i, k);
	update(index * 2 + 1, mid + 1, r, i, k);
	st[index] = max(st[index * 2], st[index * 2 + 1]);
}

int querypos(int index, int l, int r, int k){
	if(st[index] < k)	return -1;
	if(l == r)	return l;
	int mid  = (l + r) / 2;
	if(st[index * 2] >= k)
		return querypos(index * 2, l, mid, k);
	return querypos(index * 2 + 1, mid + 1, r, k);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	hotel.assign(n + 2, 0);
	ram.assign(m + 2, 0);
	st.assign(4 * n + 2, 0);
	
	for(int i = 1; i <= n; i++){
		cin>>hotel[i];
		update(1, 1, n, i, hotel[i]);
	}
	for(int i = 1; i <= m; i++){
		ll k;
        cin >> k;
        ll res = querypos(1, 1, n, k) ;
        if(res == -1) res = 0;
        cout << res << " ";
        if(res!=0) update(1, 1, n, res, -k);
	}
}
