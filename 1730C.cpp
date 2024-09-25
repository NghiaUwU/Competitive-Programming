#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector <int> waiting;
void solving(){

    
    string s;
    cin>>s;
    int max = 9;
    int num = 9;
    for(int i = s.size() - 1; i >= 0; i--){
         num =  min(num, s[i] - 48);
        int seeding = s[i] - 48;
        if(i != s.size() - 1){
            int check = (s[i] - 48) + 1;
            if((s[i] - 48) > num)     seeding = min(check, 9);
           // cout<<seeding<<" "<<num<<endl;
        }
        waiting.push_back(seeding);
        
    }
    //cout<<endl;
    sort(waiting.begin(), waiting.end());
    for(int i = 0; i < waiting.size(); i++) cout<<waiting[i];
    cout<<endl;
    waiting.clear();
    return;
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
    exit(0);
}