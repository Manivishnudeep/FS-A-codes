/*
You will be given a word 'w' and a group of words 'g'. 

check if 'w' can be broken into a space separated characters of one or more in the given group of words 'g'

Note the same word in the group of words may be re used multiple times in the breaking. 

The first line of input contains the group of words(g) followed by a word(w)

if it can done print true else print false

input=fleet gold
fleetgold
output=true

Explanation: prints true because fleetgold  can be broken as fleet gold

input=apple pen
applepenapple
output=true

Explanation: print true because "applepenapple" can be broken as "apple pen apple".
Note that you are allowed to reuse group of words

input=cats dogs and and cat
catsandog
output=false
*/
#include <bits/stdc++.h>

using namespace std;
bool solve (int ind, string s, vector<string> v,int dp[]){
    if (ind >= s.size())
        return true;
    if (dp[ind] != -1)
        return dp[ind];
    string str;
    for(int i= ind; i< s.size(); i++){
        str+= s[i];
        if(find(v.begin(),v.end(), str) != v.end()){
            bool check = solve (i+1,s,v,dp);
            if(check == true)
                return dp[ind]= true;
        }
    }
    return dp[ind]= false; 
}
int main(){
    vector<string> v;
    while(1){
        string s;
        cin>>s;
        v.push_back(s);
        if(cin.peek()=='\n'){
            break;
        }
    }
    string str;
    cin>>str;
    int n=str.length();
    int dp[n];
    memset(dp,-1,sizeof(dp));
    if(solve(0,str,v,dp)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}


