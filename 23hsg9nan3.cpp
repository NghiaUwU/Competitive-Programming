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
        int n, k;
        long long c[200005];
        priority_queue <int, vector <int> > stk;
        map <int, int> dif;
        void solve(){
            cin>>n>>k;
            for(int i = 1; i <= n; i++){
                cin>>c[i];
                dif[c[i]]++;
            }

            for(int i = 1; i <= k; i++)
                if(dif[i] > 0)  stk.push(dif[i]);

            int t1, t2, ans = 0;
            while(!stk.empty()){
                t1 = stk.top();
                stk.pop();
                t2 = stk.top();
                stk.pop();
                if(t1 > 0 && t2 > 0){
                    ans += 2;
                    t1--;
                    t2--;
                    stk.push(t1), stk.push(t2);
                }
                else    break;
            }

            cout<<ans;

        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();

}