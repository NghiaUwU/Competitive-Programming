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
struct Point{
    long long x, y;
};
Point a, b, c, d;
long long curse(Point a, Point b, Point c){
    // tich cheo
    long long val = (c.x - b.x) * (b.y - a.y) - (b.x - a.x) * (c.y -b.y);
    if(val > 0) return 1;
    else if(val < 0)    return 2;
    return 0;
}

bool fex(Point a, Point b, Point c){
    return (c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x) && c.y <= max(a.y, b. y) && c.y >= min(a.y, b.y));
}
void solve(){
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    long long ori1 = curse(a, b, c);
    long long ori2 = curse(a, b, d);
    long long ori3 = curse(c, d, a);
    long long ori4 = curse(c, d, b);

    if(ori1 != ori2 && ori3 != ori4)    cout<<"YES"<<endl;
    else if(ori1 == 0 && fex(a, b, c))   cout<<"YES"<<endl;
    else if(ori2 == 0 && fex(a, b, d))   cout<<"YES"<<endl;
    else if(ori3 == 0 && fex(c, d, a))   cout<<"YES"<<endl;
    else if(ori4 == 0 && fex(c, d, b))   cout<<"YES"<<endl;
    else    cout<<"NO"<<endl;
}   
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll test = read();
    inverse(test){
        solve();
    }

}