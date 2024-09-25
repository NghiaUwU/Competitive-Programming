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


long long n, m;

map <string, int> fre;
string ghll[5002];
char matrix[5001][5001];
vector <int> pos, temppos;
string s;
void solve(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>s;
        for(int j = 0; j < s.size(); j++)
            matrix[i][j] = s[j];
        }
    int i;
    for(int i = 0; i < m; i++) pos.push_back(i);
    for(i = n; i >= 1; i--){
        bool simi = true;
        if(pos.empty()) break;
        for(int j = 0; j < pos.size(); j++){ 
            
            ghll[pos[j]] += matrix[i][pos[j]];
            fre[ghll[pos[j]]]++;
            
            if(fre[ghll[pos[j]]] > 1)    simi = false;

        }
       
        if(simi == true){
            break;
        }
        for(int j = 0; j < pos.size(); j++){
            //cout<<pos[j]<<' ';
            //cout<<ghll[pos[j]]<<'\n';
            //ghll[j] += matrix[i][pos[j]];
            
            if(fre[ghll[pos[j]]] > 1)    temppos.push_back(pos[j]);
        }
        
        //for(int i = 0; i < temppos.size(); i++) cout<<temppos[i]<<' ';
        //cout<<'\n';
        //cout<<'\n';
        pos = temppos;
    }


    cout<<i - 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("DELROW.INP", "r")){
        freopen("DELROW.INP", "r", stdin);
        freopen("DELROW.OUT", "w", stdout);
    }
    solve();

}