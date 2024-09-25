#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;

bool check(char a, char b){
    if(a == 'Y' && b == 'e')    return true;
    if(a == 'e' && b == 's')    return true;
    if(a == 's' && b == 'Y')    return true;
    else    return false;
}

class SOL{
    public:
        str s;
        void solve(){
            cin>>s;
            if(s.size() == 1){
                if(s[0] == 'Y' || s[0] == 'e' || s[0] == 's'){
                    cout<<"YES"<<"\n";
                    return;
                }
                else{
                    cout<<"NO"<<"\n";
                    return;
                }
            }
            for(int i = 0; i < s.size() - 1; i++){
                if(!check(s[i], s[i + 1])){
                    cout<<"NO"<<"\n";
                    return;
                }
            }
            cout<<"YES"<<"\n";
        }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    SOL GHL;

    int test;
    cin>>test;
    while(test--){
        GHL.solve();
    }
}