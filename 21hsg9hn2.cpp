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

long long mx = 0, cnt = 0;

int n;
        char matrix[5005][5005];
        long long vote[5005];
        void solve(){
            cin>>n;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    cin>>matrix[i][j];
                    if(matrix[i][j] == 'X') vote[j]++;
                }
            }

            //cout<<"TATICS"<<'\n';

            for(int i = 1; i <= n; i++){
                //cout<<vote[i]<<' ';
                if(vote[i] == mx)   cnt++;
                if(vote[i] > mx){
                    cnt = 1;
                    mx = vote[i];
                }
            }

            cout<<cnt<<' '<<mx<<'\n';
            for(int i = 1; i <= n; i++){
                if(vote[i] == mx)   cout<<i<<' ';
            }
        }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("VOTE.inp", "r")){
        freopen("VOTE.inp", "r", stdin);
        freopen("VOTE.out", "w", stdout);
    }
    SOL GHL;
    solve();

}