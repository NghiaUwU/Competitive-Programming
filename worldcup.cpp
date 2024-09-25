#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[100005];
int n;
int b[100005];
long long ans = 1e18;
int check;
const int INF = 1e9 + 90 ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
	int n; 
    cin>>n;
	
	vector<int> v(n);
	for(int &x : v ) cin>>x;
	
	int mn= INF, ind=-1 ;
	
	for(int i = 0 ; i < n; i++){
		int t = n;
		int need = max(0,v[i]-i );
		need = ceil((double)need/t);
		if(mn > need ){
			ind = i+1; 
			mn = need ; 
		}
	}
	
    cout<<ind;

    return 0;
}