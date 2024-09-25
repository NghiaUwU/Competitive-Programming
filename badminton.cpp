#include <bits/stdc++.h>
using namespace std;

void solving(){
    int n, x, y;
    cin>>n>>x>>y;
    if(x > y)   swap(x, y);
    if(x == 0 && y == 0){
        cout<<"-1"<<endl;
        return;
    }
    if(x != 0 && y != 0){
        cout<<"-1"<<endl;
        return;
    }
    int match = n -1;
    if(match % y != 0){
        cout<<"-1"<<endl;
        return;
    }
    else{
        int sus = match / y;
        for(int i = 1; i <= match; i++){
            for(int j = 1; j <= y; j++){
                cout<<i + 1<<" ";
                if(j == y)  i += j - 1;
            }
        }
    }
    cout<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    kill_dependency(test);
    cin>>test;
    while(test--){
        solving();
    }
}