#include<bits/stdc++.h>
using namespace std;

deque<char> Brackets_check(string s)
{
    deque<char> brackets;
    for(int i = 0; i < s.size(); i ++)
    {
        if(s[i] == '(')
        {
            brackets.push_back(s[i]);            
        }

        if(s[i] == ')')
        {
            if(!brackets.empty() && brackets.back() == '(')
            {
                brackets.pop_back();                
            }
            else
            { 
                brackets.push_back(s[i]);
            }            
        }
    }
    return brackets;
}

int main()
{
    freopen("parentheses.inp", "r", stdin);
    freopen("parentheses.out", "w", stdout);

    string s;
    cin >> s;
    vector<char> S;

    deque<char> Z = Brackets_check(s);

    if(Z.size() == 0)
        return cout << 0, 0;
    
    int i = 0;
    while(Z.size())
    {
        S.push_back(Z.front());
        Z.pop_front();
    }
    

    int OpenCount = 0, CloseCount = 0;
    for(int i = 0; i < S.size(); i ++)
    {
        if(S[i] == '(')
            OpenCount ++;
        else CloseCount ++;
    }
    
    if(OpenCount == CloseCount)
        cout << OpenCount;
    else cout << -1;
}