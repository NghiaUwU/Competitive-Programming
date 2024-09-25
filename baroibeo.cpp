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
long long dp[20][180][3];
vector <int> digit;
vector <int> digitB;
void getDig(long long x){
    digit.clear();
    while(x){
        digit.push_back(x % 10);
        x /= 10;
    }
}
void getDigB(long long x){
    digitB.clear();
    while(x){
        digitB.push_back(x % 10);
        x /= 10;
    }
}
long long dpDIGIT(int idx, int cnt, int tight, vector <int> &digit){
    if(idx == -1)   return (cnt > 0 && cnt <= 3);
    if(cnt > 3)     return 0;

    if(dp[idx][cnt][tight] != -1 && !tight)  return dp[idx][cnt][tight];

    long long record = 0;

    int limit = (tight)? digit[idx] : 9;
    for(int i = 0; i <= limit; i++){
        int newlimit = (digit[idx] == i)? tight : 0;

        record += dpDIGIT(idx - 1, cnt + (i > 0) , newlimit, digit);    
    }

    if(!tight)  dp[idx][cnt][tight] = record;
    //cout<<record<<' ';
    return record; 
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //SOL GHL;
    //GHL.solve();
    

    int t;
    cin>>t;
    memset(dp, -1, sizeof(dp));
    while(t--){
        

        long long a, b;
        cin>>a>>b;
        getDig(a - 1);
        long long ana = dpDIGIT(digit.size() - 1, 0, 1, digit);
        getDigB(b);
        long long anb = dpDIGIT(digitB.size() - 1, 0, 1, digitB);
        //cout<<anb<<'\n';
        cout<<anb - ana<<'\n';
    }


}