#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

class SOL{
    public:
        long long n;
        void res(){
            cin>>n;
            long long mid = n / 2;
            long long mod = n % mid;
            long long mod2 = n % (mid + 1);
            //long long mod3 = n % (mid - 1);
            if(mod == max(mod , mod2))  cout<<mid<<'\n';
            else if(mod2 == max(mod, mod2)) cout<<mid + 1<<'\n';
        }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("BAI3.INP", "r")){
        freopen("BAI3.INP", "r", stdin);
        freopen("BAI3.OUT", "w", stdout);
    }
    int test;
    cin>>test;

    while(test--){
        SOL GHL;
        GHL.res();
    }
}