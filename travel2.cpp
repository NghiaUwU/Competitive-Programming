#include <bits/stdc++.h>
using namespace std;
vector <int> tp1;
vector <int> tp2;
int cnt = 0;
void update(int index, int l, int r, int i, int k){
	//cout<<tp1[index]<<" "; 
	if(l == r){
		tp1[index] = 0;	
		
		tp1[index] += k; 
		//cout<<tp1[index]<<" "; 
		return;
	}
	
	int mid = (l + r) / 2;
	if (mid < i)	update(index * 2 + 1, mid + 1, r, i, k);
	else update(index * 2, l, mid, i, k);
	
	tp1[index] = min(tp1[index * 2], tp1[index * 2 + 1]); 
	
}
void update2(int index, int l, int r, int i, int k){
//	cout<<tp2[index]<<" "; 
	if(l == r){
		tp2[index]= 0;	
		
		tp2[index] += k; 
		return;	
	}
	int mid = (l + r) / 2;
	if(mid < i)	update2(index * 2 + 1, mid + 1, r, i, k);
	else update2(index * 2, l, mid, i, k);
	
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
	
	int n, q, x, y, c, v, k;
	cin>>n>>q;
	tp1.assign(4 * n + 2, 1e9);
	tp2.assign(4 * n + 2, 1e9);
	for(int i = 1; i < n; i++)	cin>>x>>y;
	while(q--){
		cin>>c;
		if(c == 1){
			cin>>v>>k;
			cnt++;
			//cout<<"TP1"<<endl;
			update(1, 1, n, v, k - v); // truoc
			//cout<<endl<<"TP2"<<end
			update2(1, 1, n, v, k + v); // sau			
			//cout<<endl;
		}
		else{
			cin>>v;
			int supreme = v - 1;
			if(cnt == 0){
				cout<<supreme<<endl;
				continue;
			}
			//cout<<endl;
			
			cout<<min(supreme,min(ask1(1, 1, n, 1, v) + v,ask2(1, 1, n, v + 1, n) - v))<<endl;
		} 
	}
}

