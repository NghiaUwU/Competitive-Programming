#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long ghl = 15052007;
const long long anniversary = 11102022;
const string every_second_with_you = "esctasy";


int n, m;
int k = -1;

ll mx = 0;
ll a[100005], storage[100005], maxi[100005];
map <ll, int> staircount;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("CLIMBSTAIR.INP", "r")){
        freopen("CLIMBSTAIR.INP", "r", stdin);
        freopen("CLIMBSTAIR.OUT", "w", stdout);
    }


    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        maxi[i] = max(maxi[i - 1], a[i]);
        if(mx < a[i]){
            staircount[mx] = i - 1;
            storage[++k] = mx;
            mx = a[i];
            
        }
    }

    ll search;
    
    for(int i = 1; i <= m; i++){

        
        cin>>search;
        //cout<<"CASE "<<i<<'\n';
        int l = 1, r = n;
        ll check = -110;
        while(l <= r){

            //cout<<l<<" "<<r<<" "<<mid<<" "<<search<<" "<<storage[mid]<<'\n';

            int mid = (l + r) / 2;
            if(maxi[mid] <= search){
                check = mid;
                l = mid + 1;
            }
            else    r = mid - 1;
           //
            /*
            if(search == storage[mid]){
                //cout<<staircount[storage[mid]]<<'\n';
                break;
            }
            else if(search > storage[mid])  l = mid + 1;
            else    r = mid - 1;
            */
        }

        if(check == -110)   cout<<0<<'\n';
        else       cout<<check<<'\n';
        //cout<<l<<" "<<r<<'\n';
        //if(l > r)   cout<<staircount[storage[r]]<<'\n';
        //if(l == r)  cout<<staircount[storage[l]]<<'\n';
    }

    
}