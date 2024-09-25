#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

//  ~~ * ~~ NGHIA HAS GH ~~ * ~~ //
//  ~~ * ~~ NGHIA belongs to GHL ~~ * ~~

const long long ghl = 15052007;
const long long anniversary = 11102022;
const bool i_love_you_so_much = true; 
const long long MOD = 1e9 + 7;
const long long MAX = 1e18;

// ~~ * ~~ * ~~ *  ~~ *  ~~ * ~~ * //


ll uoc[1000005];
void sanguoc(){
    for(int i = 2; i * i <= 1000005; i++){
        for(int j = i; j <= 1000005; j += i){
            uoc[j]++;
        }
    }
}
int n;
ll a[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("MATONG.INP", "r")){
        freopen("MATONG.INP", "r", stdin);
        freopen("MATONG.OUT", "w", stdout);
    }
    
    sanguoc();
    cin>>n;
    ll tong = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        //cout<<uoc[a[i]] + 1<<' ';
        tong += a[i] * (uoc[a[i]] + 1);
    }
   // cout<<'\n';

    cout<<tong;

}