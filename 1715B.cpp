#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long avo = 17012007;
void solve(){
    ll n, k, b, s;
    cin>>n>>k>>b>>s;
    int largest_mod = k - 1;
    long long canbeconsequence = largest_mod * n;
    if(b * k > s){
        cout<<"-1"<<endl;
        return;
    }
    if(s > b * k + canbeconsequence || s < b * k){
        cout<<"-1"<<endl;
        return;
    }
    if(s / k == b){
        for(int i = 1; i < n; i++)  cout<<"0 ";
        cout<<s<<endl;
        return;
    }
    long long mod = s - b * k;
    //cout<<mod<<" ";
    long long highestmem = b * k + (k -1);
    //cout<<highestmem;
    mod -= largest_mod;
    for(int i = 1; i < n; i++){
        if(mod == 0){
            cout<<"0 ";
        }
       if(mod != 0){
         if(mod >= largest_mod){
            cout<<largest_mod<<" ";
            mod -= largest_mod;
            continue;
        }
        if(mod < largest_mod){
            cout<<mod<<" ";
            mod = 0;
            continue;
        }
       }

    }
    cout<<highestmem<<endl;
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int test;
    cin>>test;

    while(test--){
        solve();
    }
}