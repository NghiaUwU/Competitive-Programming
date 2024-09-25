
/*
 * what is the similarity between DFS and BFS? They are both fking recursion. '
 * 
 * 
 * Btw, i love blue, because it's just like my crush
 * whose name is ~Khue~, who is a famous and gorgeous girl.
 */

#include<bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef unsigned long long sll;

const long long khue = 221006;
const long long khuenghia = 221106250907;

struct act
{
	char a;
	long long loc;
};

bool comp(pair<int, int> a, pair<int, int> b){return a.first > b.first;}

void solvingforquery()
{

	str s;
	cin>>s;
	vector<pair<int, int>> jump;


    for(int j = 0; j < s.size(); j++) if((s[j] >= s[0] && s[j] <= s[s.size() - 1]) || (s[j] <= s[0] && s[j] >= s[s.size() - 1])) jump.push_back(make_pair(s[j], j+1));
        cout<<abs(s[0] - s[s.size() - 1])<<" "<<jump.size()<<endl;

    if(s[0] > s[s.size() - 1]) sort(jump.begin(), jump.end(), comp);
    else sort(jump.begin(), jump.end());

    for(int j = 0; j < jump.size(); j++) cout<<jump[j].second<<" ";
        cout<<endl;
}

int main()
{
	long long n;
	cin >> n;

    while(n--)  solvingforquery();
}

    
