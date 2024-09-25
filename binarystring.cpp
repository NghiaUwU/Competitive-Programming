#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string zero = "0";
string one = "1";
string transfer;
map <int, int> check;
int dif = 0;
long long number(string s){
    long long num = 0;
    for(int i = 0; i < s.size(); i++){
        int nus = s[s.size() - i - 1] - 48;
        
        if(nus == 1)    num += pow(2, i);
    }
    return num;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;
    while(n > 0){
        if(n % 2 == 0)  transfer += zero;
        else    transfer += one;
        n /= 2;
    }
    reverse(transfer.begin(), transfer.end());

    string chosen;
    cout<<transfer<<endl;

    for(int i = 0; i < transfer.size(); i++){
        for(int j = 0; j <= i; j++){
            chosen = "";
            for(int x = j; x <= i; x++){
                chosen += transfer[x];
            }
            cout<<chosen<<" "<<number(chosen)<<endl;
            check[number(chosen)]++;
            if(check[number(chosen)] == 1)  dif += number(chosen);
        }
    }
    cout<<dif;
}
