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




string s;
int n, cnt = 0;
void solve(){
    cin>>n;
    cin>>s;
    map <string, int> diction;
    cnt = 0;
    for(int i = 0; i < s.size() - 1; i++){
        string temp = "";
        temp += s[i];
        temp += s[i + 1];
        diction[temp]++;
        if(diction[temp] == 1){
            cnt++;
            //cout<<">> "<<temp<<'\n';
        }
    }

    cout<<cnt<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    while(test--)
        solve();

}