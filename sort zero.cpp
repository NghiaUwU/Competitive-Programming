#include <iostream>
#include <stdlib.h>
#include <utility>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset> 
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <array>
#include <string_view>
#include <cmath>
#include <cctype>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <stdexcept>
#include <streambuf>
#include <typeinfo>
#include <new>
#include <numeric>
#include <ostream>
#include <iomanip>
#include <unordered_map>
#include <string>
using namespace std;

typedef long long ll;
typedef string str;
typedef unsigned long long ull;
#define end exit(0);
#define skip continue;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inverse(n)  while(n--)

const double pi = 3.14159265359;
const long long BIG = 1e18;
const long long MAXARRAY = 1e5 + 1;
const long long MAX2ARRAY = 1e6 + 1;
const long long MAX3ARRAY = 1e7 + 7;
const long long MOD = 1e9 + 7; 
const long long MAX = 1e9;
const long long siz = 1e6;
const long long vex = 1e7;
const long long modnew = 2004010501;
const long long SMALL = -1e18;

ll read(){ll n; cin>>n; return n;}
str readstr(){string s; cin>>s; return s;}
str readspace(){string s; getline(cin, s); return s;}
char readchar(){char a; cin>>a;return a;}

void solve(){
    int n = read();
    int a[100005];
    int cnt[100005];
    int search[100005];
    bool turned[100005];

    memset(cnt, 0, sizeof(cnt));
    memset(search, 0, sizeof(search));
    memset(turned, false, sizeof(turned));

    for(int i = 1; i <= n; i++){
        a[i] = read();
        cnt[a[i]]++;
        
        
        if(cnt[a[i]] == 1){
            search[i] = search[i - 1] + 1;
        }
        else    search[i] = search[i - 1];
        
    }

    int final_res = 0;
    for(int i = n - 1; i >= 1; i--){
        if(a[i + 1] < a[i]){
            turned[a[i]] = true;
            //cout<<"SEARCH "<<i<<" "<<search[i]<<endl;
            final_res = search[i];
            for(int j = i; j >= 1; j--) turned[a[j]] = true;
            break;
        }
    }

    for(int i = n; i >= 2; i--){
        //cout<<a[i]<<endl;
        if(turned[a[i]] == true){
            //cout<<"catch"<<endl;
            final_res = search[i];
            //cout<<"SEARCH "<<i<<" "<<search[i]<<endl;
            break;
        }
    }
    cout<<final_res;
    
    cout<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;

    while(test--){
        //cout<<"CASE "<<test<<":"<<endl;
     solve();
    }
}
/*CASE 4:1 0
2 0
1 0
1

CASE 3:1 0
1 0
2 0
2 0
0

CASE 2:1 0
1 0
1 0
1 0
1 0
5

CASE 1:1 0
1 0
1 0
2 0
3

CASE 0:1 0
0
*/