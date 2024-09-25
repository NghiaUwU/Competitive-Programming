#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long ghl = 15052007;
const long long anniversary = 11102022;
const string every_second_with_you = "esctasy";

//const long long MOD = 1e9;
long long a[100005];

int sum = 0;
int dequy(int i, int doop){
    if (i == 0)
        return abs(sum - doop - doop);

    else return min(dequy(i - 1, doop + a[i]), dequy(i - 1, doop));
}
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("CANDY.INP", "r")){
        freopen("CANDY.INP", "r", stdin);
        freopen("CANDY.OUT", "w", stdout);
    }
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum += a[i];
    }
    cout<<dequy(n, 0);

}

