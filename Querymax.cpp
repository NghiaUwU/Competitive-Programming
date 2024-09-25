#include <bits/stdc++.h>
using namespace std;
#define int long long
#define string str 
typedef long long ll;
long long L[400005]={},R[400005]={},leaf[400005]={},Sum[400005]={},a[400005]={};
void Build(int x,int low,int high){
    L[x]=low;
    R[x]=high;
    if (low==high){
        leaf[low]=x;
        Sum[x]=a[low];
    }
    else{
        int mid=(low+high)/2;
        Build(2*x,low,mid);
        Build(2*x+1,mid+1,high);
        Sum[x]=max(Sum[2*x],Sum[2*x+1]);
    }
}
int uk, uw;
void UpdateIn(int x){
	if(L[x] == R[x]){
		Sum[x] = uw; 
		return;
	}
	int middle = (L[x] + R[x]) / 2;
	uk <= middle ?
		UpdateIn(2 * x) : UpdateIn(2 * x + 1);
	Sum[x] = max(Sum[2 * x] , Sum[2 * x + 1]); 
} 
void Update(int k, int w){
	uk = k;
	uw = w;
	UpdateIn(1);
}
int qi, qj;
int Req(int x){
	if(R[x] < qi or L[x] > qj){
		return 0;
	}
	if(L[x] >= qi and R[x] <= qj)	return Sum[x];
	return max(Req(2 * x) , Req(2 * x + 1));
}
int Que(int i , int j){
	qi = i;
	qj = j;
	return Req(1);
}
ll n, m;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	Build(1, 0, n);
	while(m--){
		char c;
		ll a, b;
		cin>>c>>a>>b;
		if(c == 'S'){
			Update(a, b);
		}
		else{
			cout<<Que(a, b)<<endl;
		}	
	}
	
}
