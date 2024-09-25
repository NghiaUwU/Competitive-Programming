#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string ans[10005];
string res = "";
void tinh(string a,string b)
{
    res="";
    int nho=0;
    int kq;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int lena=a.size();
    int lenb=b.size();
    string tam;
    if(lena<=lenb)
    {
        tam=b;
        b=a;
        a=tam;
    }
    lena=a.size();
    lenb=b.size();
    if(lena>=lenb)
    {
        for(int i=0; i<lena; i++)
        {
            if(i<lenb)
            {
                kq=(int(a[i])+int(b[i])-48*2)+nho;
                
                if(kq>=10)  nho = 1;
                
                else    nho = 0;
                

                res+=char(kq%10+48);
            }
            else{
                kq=int(a[i])-48+nho;
                nho=0;
                res+=char(kq%10+48);
            }

        }
        if(nho==1)
        {
            res+="1";
        }
    }


    reverse(res.begin(),res.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    while(cin>>n){
        ans[1] = "1";
        ans[2] = "1";
        for(int i =  3; i <= n; ++i){
            tinh(ans[i - 1], ans[i - 2]);
            ans[i] = res;
        }
        cout<<ans[n]<<'\n';
    }
}