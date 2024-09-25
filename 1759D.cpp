// MAKE IT ROUND
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

class SOL{
    public:
        ll n, m;
        int poweroftwo(ll n){  // num a
            int cnt = 0;
            while(n % 2 == 0){
                cnt++;

                n /= 2;
            }
            return cnt;
        }

        int poweroffive(ll n){  // num a
            int cnt = 0;
            while(n % 5 == 0){
                cnt++;

                n /= 5;
            }
            return cnt;
        }

        long long greedy(ll target, ll p2, ll p5){
            long long need = 1;
            
                while(p2 < p5 && need * 2 <= target){
                    p2++;
                    need *= 2;
                }
                while(p5 < p2 && need * 5 <= target){
                    p5++;
                    need *= 5;
                }

            while(need * 10 <= target){
                need *= 10;
                p2++;
                p5++;
            }
            return need;
        }
        
        
        void solve(){
            cin>>n>>m;
           

            //cout<<poweroftwo(n)<<" "<<poweroffive(n)<<"\n";
            //cout<<greedy(m, poweroftwo(n), poweroffive(n))<<"\n";
            long long found = greedy(m, poweroftwo(n), poweroffive(n));
            //cout<<found<<endl;
            cout<<n * (m / found) * found<<"\n";
        }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;

    while(test--){
        SOL GHL;
        //cout<<"TEST "<<"\n";
        GHL.solve();    
    }
}