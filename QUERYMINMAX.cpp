#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string str 
typedef long long ll;
long long L[400005]={},R[400005]={},leaf[400005]={},Sum[400005]={},a[400005]={};
long long SMALL[400005];
void Build(int x,int low,int high){
    L[x]=low;
    R[x]=high;
    if (low==high){
        leaf[low]=x;
        Sum[x]=a[low];
        SMALL[x] = a[low];
    }
    else{
        int mid=(low+high)/2;
        Build(2*x,low,mid);
        Build(2*x+1,mid+1,high);
        Sum[x]=max(Sum[2*x],Sum[2*x+1]);
        SMALL[x] = min(SMALL[2 * x], SMALL[2 * x + 1]);
    }
}
int uk, uw;
void UpdateIn(int x){
	if(L[x] == R[x]){
		Sum[x] = uw; 
		SMALL[x] = uw;
		return;
	}
	int middle = (L[x] + R[x]) / 2;
	uk <= middle ?
		UpdateIn(2 * x) : UpdateIn(2 * x + 1);
	Sum[x] = max(Sum[2 * x] , Sum[2 * x + 1]); 
	SMALL[x] = min(SMALL[2 * x], SMALL[2 * x + 1]);
} 
void Update(int k, int w){
	uk = k;
	uw = w;
	UpdateIn(1);
}
int qi, qj;
int Reqmax(int x){
	if(R[x] < qi or L[x] > qj){
		return 0;
	}
	if(L[x] >= qi and R[x] <= qj)	return Sum[x];
	return max(Reqmax(2 * x) , Reqmax(2 * x + 1));
}
int Reqmin(int x){
	if(R[x] < qi or L[x] > qj){
		return INT_MAX;
	}
	if(L[x] >= qi and R[x] <= qj)	return SMALL[x];
	return min(Reqmin(2 * x) , Reqmin(2 * x + 1));
}
int Que(int i , int j){
	qi = i;
	qj = j;
	return Reqmax(1) - Reqmin(1);
}
ll n, m, num;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	Build(1, 0, n);
	for(int i = 1; i <= n; i++){
		cin>>num;
		Update(i, num);
	}
	while(m--){
		
		ll a, b;
		cin>>a>>b;
		cout<<Que(a, b)<<endl;
			
	}
	
}

