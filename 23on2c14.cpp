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
bool oneandzero = true;
long long a[1000006];
        int n;
        int ans = 0;
        long long len = 0;
        long long sum = 0, sumand = 0;
        void solve(){
            cin>>n;
            for(int i = 1; i <= n; i++){
                cin>>a[i];
                if(a[i] != 0 && a[i] != 1)  oneandzero = false;
            }

            if(oneandzero == false){
                for(int i = 1; i <= n; i++){
                sum = a[i];
                sumand = a[i];
                for(int j = i + 1; j <= n; j++){
                    sumand &= a[j];
                    sum ^= a[j];
                    if(sumand > sum)    ans = max(ans, j - i + 1);
                }
            }

            }
            else{
                int len = 0;
                for(int i = 1; i <= n; i++){
                    if(a[i] == 1)   len++;
                    else{
                        ans = max(ans, len);
                        len = 0;
                    }
                }
                ans = max(ans, len);
                //return;
            }
            cout<<ans;
        }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    solve();

}