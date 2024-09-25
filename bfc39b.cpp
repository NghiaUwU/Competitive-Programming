#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SOL{
    public:
        string s;
        long long n;

        map <int, int> cntswap;

        void solve(){
            cin>>s;
            cin>>n;
            for(int i = 1; i <= n; i++){
                int x;
                cin>>x;
                cntswap[x - 1]++;
            }
            long long power = 0;
            vector <char> waiting;
            char fir, sec;
            for(int i = 0; i < s.size() / 2; i++){
                power += cntswap[i];
                fir = s[i];
                sec = s[s.size() - i - 1];
                if(power % 2 != 0){
                    sec = s[i];
                    fir = s[s.size() - i - 1];

                    //cout<<fir<<" "<<sec<<'\n';
                }
                waiting.push_back(fir);
                waiting.push_back(sec);

                
            }
            if(s.size() % 2 != 0)   waiting.push_back(s[s.size() / 2]);
            //for(int i = 0; i < waiting.size(); i++) cout<<waiting[i]<<" ";

            vector <char> trasform;

            for(int i = 0; i < waiting.size(); i++){
                if(i % 2 == 0)  cout<<waiting[i];
                else    trasform.push_back(waiting[i]);
            }

            for(int i = trasform.size() - 1; i >= 0; i--){
                cout<<trasform[i];
            }
            

        }
        
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}