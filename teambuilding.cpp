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

int opposite(int n){
    if(n == 1)  return 2;
    else    return 1;
}
vector  < int > relate[100005];
int gr[100005];
bool visited[100005];
int pre[100005];
bool bfs(int a){
    queue <int> q;
    q.push(a);
    visited[a] = true;
    gr[a] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : relate[u]){
            if(gr[v] == gr[u])  return 0;
            if(visited[v])  continue;
            if(visited[v] == false){
                visited[v] = true;
                gr[v] = opposite(gr[u]);
                q.push(v);
            }
        }
    }
    return 1;

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = read();
    int path = read();

    while(path--){
        int u = read();
        int v = read();

        relate[u].push_back(v);
        relate[v].push_back(u);
    }
    
    memset(visited, false, sizeof(visited));
    gr[1] = 1;
    for(int i = 1; i <= n; i++){
        if(visited[i] == false){
            if(!bfs(i)){
                cout<<"IMPOSSIBLE";
                end
            }
        }
    }
for(int i = 1; i <= n; i++){
    cout<<gr[i]<<" ";
}
}