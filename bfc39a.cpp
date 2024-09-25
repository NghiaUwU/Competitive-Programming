#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SOL{
    public:

        string card[10];
        pair <char, char> base[10];

        map <char, int> number;
        map <char, int> chat;

        int k = 0,c = 0;
        char lis[10], lischat[10];
        void solve(){
            for(int i = 1; i <= 5; i++){
                cin>>card[i];

                for(int j = 0; j < 2; j++){

                    //cout<<card[i][j]<<" ";
                    if(j == 0){
                        number[card[i][j]]++;
                        
                        if(number[card[i][j]] == 1){
                            lis[++k] = card[i][j];
                            //out<<"SAVE NUMBER"<<'\n';
                        }
                    }
                    else{
                        chat[card[i][j]]++;
                        if(chat[card[i][j]] == 1){
                            lischat[++c] = card[i][j];
                            //cout<<"SAVE CHAT"<<'\n';
                        }
                    }
                }

                //cout<<'\n'; 
                
                
            }
            bool thung = false, doi = false;
            bool tuquy = false;
            bool sam = false, thu = false;
            bool sanh = false;

            //cout<<c;
            if(c == 1){
                thung = true;
            }
            int numberoftwo = 0;
            if(k == 5){
                int rechange[104];
                for(int i = 1; i <= k; i++){
                    if(lis[i] == 'T')   rechange[i] = 10;
                    else if(lis[i] == 'J')  rechange[i] = 11;
                    else if(lis[i] == 'Q')  rechange[i] = 12;
                    else if(lis[i] == 'K')  rechange[i] = 13;
                    else if(lis[i] == 'A')  rechange[i] = 14;

                    else    rechange[i] = lis[i] - 48; 
                    
                }
                sort(rechange + 1, rechange + 1 + k);
                sanh = true;
                for(int i = 1; i < k; i++){
                    //cout<<rechange[i]<<" ";
                    if(rechange[i] + 1 != rechange[i + 1])  sanh = false;
                }
                //if(sanh == false)   cout<<"FALSE";
            }
            if(k >= 2){
                for(int i = 1; i <= k; i++){
                    if(number[lis[i]] == 4) tuquy = true;
                    if(number[lis[i]] == 3) sam = true;
                    if(number[lis[i]] == 2){
                         doi = true;
                         numberoftwo++;
                    }
                }
            }

                if(thung == true && sanh == true){
                    cout<<"Thung pha sanh";
                    return;
                }
                else if(thung == true)   cout<<"Thung";
                else if(sanh == true){
                    cout<<"Sanh";
                }
                else if(tuquy == true){
                    cout<<"Tu quy";
                    return;
                }
                else if(sam == true && doi == true){
                    cout<<"Cu lu";
                    return;
                }
                else if(numberoftwo == 2){
                    cout<<"Thu";
                    return;
                }
                else if(sam == true) cout<<"Sam";
                else if(doi == true)  cout<<"Doi";
                else    cout<<"Mau thau";
        }   
        
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SOL GHL;
    GHL.solve();
}