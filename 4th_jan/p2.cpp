/*
Sunder a Military Research Team wants to decode a message(A-1,B-2...Z-26). 
If Sunder is given a Number he wants to check in how many ways the number can be written into Characters. 

For Example - 123 can be assumed as 

ABC (A-1,B-2,C-3)  
AW  (A-1,W-23)
 LC    (L-12,C-3)

Total Ways are 3. He wants to write the code to get the number of ways . Help Sunder solve the problem.

Assume the Input number will be a valid word. 

For all Invalid Outputs print 0 

input = 100
output = 0
*/
#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int countways(string s, int n)
{
    int dp[n+1]; 
    dp[0] = 1;
    dp[1] = 1;
    if(s[0]=='0')  
         return 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i]=0;
       if (s[i-1]>'0')
            dp[i] = dp[i-1];
       if (s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<'7') )
            dp[i]+= dp[i-2];
    }
    return dp[n];
}


int main(){
    string s;
    cin>>s;
    int n=s.length();
    cout<<countways(s,n);
}
