#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;

int a[5];
bool banned[12];
vector <int> suitable;
string one = "1";
string two = "2";
string three = "3";
string four = "4";
string five = "5";
string six = "6";
string seven = "7";
string eight = "8";
string nine = "9";
string zero = "0";
void update(string s, int a[]){
    for(int i = 0; i < s.size(); i++){
        a[i + 1] = s[i] - 48;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "8000";
    for(int i = 1; i <= 50; i++){

    
    update(s, a);

    }
    
    

}