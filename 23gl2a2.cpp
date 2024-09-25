#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

class SOL{
    public:
        str s;
        ll n;
        ll a = 0, b = 0, c = 0;
        void solve(){
            cin>>n;
            cin>>s;

            for(int i = 0; i < s.size(); i++){
                if(s[i] == 'A') a++;
                else if(s[i] == 'B')    b++;
                else    c++;
            }

            if(a + c == b)  cout<<"YES";
            else    cout<<"NO";
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}