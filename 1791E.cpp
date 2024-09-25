#include <bits/stdc++.h>
using namespace std;

class SOL{
    public:
        int n;
        long long a[1000005];
        long long sum = 0;
        long long am = 0;
        bool zero = false;
        void solve(){
            cin>>n;
            for(int i = 1; i <= n; i++){
                cin>>a[i];
                sum += a[i];
                if(a[i] < 0)    am++;

                if(a[i] == 0)   zero = true;
            }

            if(am == 0){
                cout<<sum<<'\n';
                return;
            }

            sort(a + 1, a + 1 + n);
           //
            if(am % 2 == 0 || (am % 2 != 0 && zero == true)){
                sum = 0;
                for(int i = 1; i <= n; i++){
                    sum += abs(a[i]);
                }
            }
            else{
                sum = 0;   
                long long at = 1e9;
                for(int i = 1; i <= n; i++){
                    sum += abs(a[i]);
                    at= min(abs(a[i]), at);
                }
                sum -= 2 * at;
            }
            cout<<sum<<'\n';
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    while(test--){
        //cout<<"TEST"<<'\n';
        SOL GHL;
        GHL.solve();
    }
}