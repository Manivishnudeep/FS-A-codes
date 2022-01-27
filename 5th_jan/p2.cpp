/*
True Or False 

Shyam is given series of  Statements
T represents True, F represents False. 

Initially all the statements will be False.
He can change from T to F or F to T . 
If he starts at one Statement, the process has to continue upto end of the statement.
He can start at any part of the Statement. 
If it is 'F' it changes to 'T' and if it is 'T' it changes to 'F'. 
He has to do minimum number of swaps on the Initial Statement to reach the given target state


Input = TFTTT
output = 3

Explanation - Initially FFFFF
Change from the Third Statement FFTTT
Change from the First Statement TTFFF
Change from the Second Statement  TFTTT

*/
#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int countop(string s){
    int n=s.length(),count=0;
    string ref="";
    for(int i=0;i<n;i++){
        ref+='F';
    }
    for(int i=0;i<n;i++){
        if(s[i]!=ref[i]){
            for(int j=i;j<n;j++){
                if(ref[j]=='T'){
                    ref.insert(j,"F");
                }
                else{
                    ref.insert(j,"T");
                }
                ref.erase(ref.begin()+j+1);
            }
            count++;
        }
    }
    return count;
}
int main(){
    string s,ref="";
    cin>>s;
    cout<<countop(s);
}
