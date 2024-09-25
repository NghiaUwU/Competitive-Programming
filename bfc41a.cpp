#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int BIT = 61;
class SOL{
    public:
        
};
long long k;
        string s;
        int n;
        int one  = 0, zero = 0;
        string convert;
        bool gotconvert = false;
        void solve(){
           
        }
 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     cin>>k>>s;
            long long sum = 0;
            long long base = pow(2, 60);
            //cout<<"GUD TO GO"<<'\n';
            for(int i = 0; i < s.size(); i++){
                if(s[i] - 48 == 0)  zero++;
                else    one++;
            }
            for(int i = BIT - 1; i >= 0; i--){
                if(k >= base){
                    k -= base;
                    convert += "1";
                    base /= 2;
                    gotconvert = true;
                }
                else{
                    if(gotconvert == true){
                        convert += "0";
                        
                    }
                    base /= 2;
                }
            }
            int l = 1;
            bool safe = false;
            int ans = 0;

            for(int i = 1; i < s.size(); i++){
                while(s.size() > convert.size() && s[i] == '1'){
                    s.erase(i, 1);
                    ans++;
                }
            }
            
           while(s.size() > convert.size()){
                s.erase(1,1);
                 ans++;
           }
	        if(s.size() == convert.size() && s > convert) ans++;

//            cout<<convert<<" "<<s;
cout<<ans;
 }
