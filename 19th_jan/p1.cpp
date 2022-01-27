/*

Gopal is given a string s, Now he has to remove duplicate letters so that every letter appears once and only once.

He must make sure that the result produces should occur in the order given in string 

Example 1:

Input = bcabc
Output = bca
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    unordered_set<char> st;
    for(int i=0;i<n;i++){
        if(st.find(s[i])==st.end()){
            st.insert(s[i]);
        }
    }
    string ans="";
    for(auto x:st){
        ans+=x;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}

