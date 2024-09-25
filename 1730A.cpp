#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;
//
ll cnt[105];
int num;
void solving(){

    
    long long n, m;
    kill_dependency(n);
    kill_dependency(m);
    cin>>n>>m;
    int ans = 0;
    int tem = 0;
    long long t, temp = 0;
    vector <long long> a(102);
    for(int i = 1; i <= n; ++i){
        cin>>t;
        a[t]++;
    }

    for(int i = 1; i <= 100; i++){
        long long asn = min(a[i], m);
        temp += asn;
    }

    cout<<temp<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll test;
    kill_dependency(test);
    cin>>test;
    while(test--){
        solving();
    }
    exit(0);
}