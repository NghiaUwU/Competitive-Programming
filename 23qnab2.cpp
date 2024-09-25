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


class SOL{
    public:
                
};


str s;
int k;
int dig[1000005];
int cnt = 0, sz = 0;
vector <int> storage;
void solve(){
    cin>>s;
    cin>>k;

    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 48 && s[i] <= 57){
            storage.push_back(s[i] - 48);
            sz = 0;
        }
    }

    if(storage.size() <= k){

        for(int i = 0; i < storage.size(); i++)    cout<<storage[i];
        return;
    }
    int temp = 0, taken;
    reverse(storage.begin(), storage.end());
    vector <int> ans;
    int dbk = k;
    while(!storage.empty() && k != 0){
        
        
        taken = storage[storage.size() - 1];
        storage.pop_back();
        temp = max(taken, temp);

       // cout<<taken<<' '<<storage.size()<<' '<<k<<'\n';
        if(taken == 9){
            k--;
            ans.push_back(temp);
            temp = 0;
        }
        //cout<<"AFTER CHANGE: "<<taken<<' '<<storage.size()<<' '<<k<<'\n';
        //if(k == 0)  break;
        if(storage.size() == k - 1){
            ans.push_back(temp);
            k--;
            break;
        }
        
    }

     //while(ans.size() > dbk)   ans.pop_back();
    for(int i = 0; i < ans.size(); i++) cout<<ans[i];
    //cout<<'\n';
    if(k != 0){
        for(int i = storage.size() - 1; i >= 0; i--) cout<<storage[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("BIGNUM.INP", "r", stdin);
    freopen("BIGNUM.OUT", "w", stdout);
    //SOL GHL;
    solve();

}