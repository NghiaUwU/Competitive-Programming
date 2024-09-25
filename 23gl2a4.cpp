#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;


const long long ghl = 15052007;
const long long anniversary = 11102022;
const string every_second_with_you = "esctasy";

class SOL{
    public:
        long long n;
        long long dis = 0;
        long long step = 0;
        void solve(){
            cin>>n;
            //long long limit = sqrt(n) + 3;
            //
            int mark = 1;
            while(dis < n){
                dis += mark;
                step++;

                if(dis >= n)    break;
                step++;
                mark++;
                dis--;

            }


            cout<<step;
        }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}