#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class SOL{
    public:
        string s;

        void solve(){
            cin>>s;

            stack <char> left, right;
            char temp;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '<'){
                    if(!left.empty()){
                        temp = left.top();
                        right.push(temp);
                        left.pop();
                    }
                }
                else if(s[i] == '>'){
                    if(!right.empty()){
                        temp = right.top();
                        left.push(temp);
                        right.pop();
                    }
                }
                else if(s[i] == '-'){
                    if(!left.empty()){
                        left.pop();
                    }   
                }
                else    left.push(s[i]);
            }
            stack <char> doop;
            while(!left.empty()){
                right.push(left.top());
                left.pop();
            }

            
            while(!right.empty()){
                cout<<right.top();
                right.pop();
            }
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}