#include <bits/stdc++.h>
using namespace std;

long long check[10000006];
const long long MAX = 1e7;
vector <long long> primelis;
map <long long, int> isPrime;
void precaculation(){
    memset(check, 0, sizeof(check));
    for(int i = 2; i * i <= MAX; i++){
        if(check[i] == 0){
            for(int j = i * i; j <= MAX; j += i){
                check[j] = 1;
            }
        }
    }

    for(int i = 2; i <= MAX; i++){
        if(check[i] == 0){
            primelis.push_back(i);
        }
    }

    for(int i = 1; i < primelis.size() - 1; i++){
        if((primelis[i] * 2) == primelis[i - 1] + primelis[i + 1]){
            isPrime[primelis[i]] = 1;
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    precaculation();

    int test;
    cin>>test;
    while(test--){
        int k;
        cin>>k;
        if(isPrime[k] == 1){
            cout<<"YES"<<'\n';
        }
        else    cout<<"NO"<<'\n';
    }
}