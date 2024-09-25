#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using type = int;

class SOL{
    public:
        pair <type, type> point[40];
        bool cuttable(type x1, type y1, type x2, type y2, type x3, type y3){
            if(x1 == x2 && x2 == x3)    return false;
            if(y1 == y2 && y2 == y3)    return false;
            // 1: LEFT DONW
            if(x1 == x2 && y1 == y3)    return false;
            // 2: LEFT UP
            if(y1 == y2 && x2 == x3)    return false;
            // 3: RIGHT DOWN
            if(y1 == y2 && x2 == x3)    return false;
            // 4: RIGHT UP
            if(y1 == y3 && x2 == x3)    return false;
            return true;

        }  
        void solve(){
            for(int i = 1; i <=  3; ++i)    cin>>point[i].first>>point[i].second;
            sort(point + 1, point + 1 + 3);
            for(int i = 1; i <=  3; ++i)    cout<<point[i].first<<" "<<point[i].second<<'\n';
            if(!cuttable(point[1].first, point[1].second, point[2].first, point[2].second, point[3].first, point[3].second))    cout<<"NO"<<'\n';
            else    cout<<"YES"<<'\n';
        }
}; 

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;

    for(int i = 0; i < test; ++i){
        SOL GHL;
        GHL.solve();
    }
}