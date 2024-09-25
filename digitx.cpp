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
const long long LIMIT = 1000006;
// ~~ * ~~ * ~~ *  ~~ *  ~~ * ~~ * //


class SOL{
    public:

};

int cntdig[1000006][10];
int f[1000006];
int mult(int x){
    //cout<<x<<' ';
    if(x < 10) return x;
    if(f[x] != -1)  return f[x];
    int ans = 1;
    while(x > 0){
        if(x % 10 > 1) ans *= x % 10;
        x /= 10;
    }
    if(ans >= 10)   return mult(ans);
    else    return ans;
}
void precaculation(){
    //cout<<"IT DOES WORK"<<'\n';
    for(int i = 1; i <= 1000000; i++){
        for(int j = 1; j <= 9; j++){
            cntdig[i][j] = cntdig[i - 1][j];            
        }

        
        f[i] = mult(i);
        //cout<<f[i];
       //cout<<'\n';

        cntdig[i][f[i]]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    memset(f, -1, sizeof(f));
    //memset(cntdig, 0, sizeof(cntdig));
    precaculation();
    
    int t, l, r, k;
    cin>>t;
    while(t--){
        cin>>l>>r>>k;
        cout<<cntdig[r - 1][k] - cntdig[l + 1][k]<<'\n';
    }

}