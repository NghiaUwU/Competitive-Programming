#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef uint64_t ull;

ll n, x;
ll a[200005], b[200005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x;
    for(int i = 0; i < n; i++){
        cin>>a[i];  
    }

     map<int,int> mp;
    int s=0; mp[0]=1; 
    int ans=0;
    for(int i = 0; i <= n; i++){
        s+=a[i]; 
        if (mp.find(s-x)!=mp.end()) ans+=mp[s-x];
        mp[s]++;
    }
    if(ans != 0){
        cout<<ans - 1;
    }
    else    cout<<ans;  
}