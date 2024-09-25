#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class SOL{
    public:
        string s;
        int k;
        int row = 0, col = 0;

        void solve(){
            cin>>k>>s;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == 'L') row--;
                if(s[i] == 'R') row++;
                if(s[i] == 'U') col++;
                if(s[i] == 'D') col--;
                if(row == 1 && col == 1){
                    cout<<"YES"<<'\n';
                    return;
                }
            }
            cout<<"NO"<<'\n';
        }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    while(test--){
        SOL GHL;
        GHL.solve();
    }
}