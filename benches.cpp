#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    long long n;
    cin>>n;
    long long f = n * (n - 1) * (n - 2) * (n -3) * (n - 4);
    cout<<(f / 120) * f;
}