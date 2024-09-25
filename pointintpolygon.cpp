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

int n, m;

struct Point{
    long long x, y;
    Point operator+(Point b){
        return {x+b.x, y+b.y};
    }
    Point operator-(Point b){
        return {x-b.x, y-b.y};
    }
}p, a[1005];
  
long long cross(Point a, Point b){
    return a.x*b.y - a.y*b.x;
}
  
long long dot(Point a, Point b){
    return a.x*b.x + a.y*b.y;
}
  
int sign(long long x){
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}
  
bool onseg(Point a, Point b, Point c){
    if (cross(c-a, b-a) != 0) return false;
    if (0 <= dot(c-a, b-a) && dot(c-a, b-a) <= dot(b-a, b-a)) return true;
    return false;
}
  
bool intersec(Point a, Point b, Point c, Point d){
    int f1 = sign(cross(a-c, d-c)) * sign(cross(b-c, d-c));
    int f2 = sign(cross(c-a, b-a)) * sign(cross(d-a, b-a));
    if (f1 < 0 && f2 < 0) return true;
    if (f1 > 0 || f2 > 0) return false;
    if (onseg(a, b, c)) return true;
    if (onseg(a, b, d)) return true;
    if (onseg(c, d, a)) return true;
    if (onseg(c, d, b)) return true;
    return false;
}
  
void point_in_polygon(Point x, Point a[]){
    for (int i = 1; i < n; i++){
        if (onseg(a[i-1], a[i], x)){
            cout << "BOUNDARY\n";
            return;
        }
    }
    if (onseg(a[n-1], a[0], x)){
        cout << "BOUNDARY\n";
        return;
    }
    Point y = x + Point{1, (long long)2e9+5};
    int cnt = 0;
    for (int i = 1; i < n; i++){
        if (intersec(x, y, a[i-1], a[i])) cnt++;
    }
    if (intersec(x, y, a[n-1], a[0])) cnt++;
    if (cnt % 2 == 1) cout << "INSIDE\n";
    else cout << "OUTSIDE\n";
}

  
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < m; i++){
        cin >> p.x >> p.y;
        point_in_polygon(p, a);
    }
}