#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

class SOL{
    public:
        int n, k;
        str s;

        void revers(bool& a){
            if(a == false)  a = true;
            else    a = false;

            return;
        }

        void dequy(string s, int l, int r, int turn, int b, int q){
            if(l > r)  return;
            if(b > k){
                cout<<"NO";
                return;
            }
            if(q > k){
                cout<<"YES";
                return;
            }

            
        }
        void solving(){
            cin>>n>>k;
            cin>>s;

            

        }
};
SOL GHL;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    GHL.solving();
}