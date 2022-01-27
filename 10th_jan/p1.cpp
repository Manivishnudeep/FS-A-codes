/*

In a South Africa Class room, each student has a name with a single character. 
Initally all the students names will be given. The teacher now wants the students 
to be shuffled, so that two students names that are adjacent to each other are not same. 

If the names can be shuffled in such a way print yes else  prints no. 

input=ddt
output=yes


Explanation -the student names can be shuffled as dtd


input=rrrt
output=no

Explanation - the studens names after shuffling will have same student names adjacent to each other 


*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    map<char,int>mp;
    
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    int flag=0;
    for(auto ch : mp)
    {
        if(ch.second>(n+1)/2){
               flag=1;
               cout<<"no";
               break;
        }
        
    }
    if(flag==0){
        cout<<"yes";
    }
     
}
