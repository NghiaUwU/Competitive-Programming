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

long long a[200005];
        long long cnt = 0;
        long long needfind = -1;
        long long mp[200005];
        map <long long, long long> fre;
        int n;

        void solve(){
            cin>>n;
            for(int i = 1; i <= n; i++){
                cin>>a[i];
                fre[a[i]]++;
                if(fre[a[i]] == 1)  mp[++cnt] = a[i];
            }
//            sort(a + 1 , a + 1 + n);
            sort(mp + 1, mp + 1 + cnt);
            for(int i = 1; i <= cnt; i++){
                if(fre[mp[i]] == 1){
                    //cout<<i;
                    needfind = mp[i];
                    break;
                }
            }

            if(needfind == -1)  cout<<"-1";
            else{
                for(int i = 1; i <= n; i++){
                    if(a[i] == needfind){
                        cout<<i;
                        return;
                    }
                }
            }
        }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

}