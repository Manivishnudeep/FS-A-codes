/*

Sundeep is working with integer sets.
He is given a set of integers nums[], consist of positive integers.
You have to find a subsequence of integet set nums[], where the sum of elements
is equal to the sum of the rest of the elements.

Check whether you are able to split the entire set nums[], into two subsequences
where the two subsequences never share the elements from same index.

If it is possible to split, print true.
otherwise print false.

The first line of input contains the size followed by array elements 

Sample Input-1:
---------------
4
4 2 8 6

Sample Output-1:
----------------
true

Explanation:
----------
[4,6] and [2,8] sum of both the sets equal to 10.


Sample Input-2:
---------------
5
2 3 4 5 8

Sample Output-2:
----------------
false

*/
#include<bits/stdc++.h>
using namespace std;
int dp[100][1000];
int solve(int arr[],int n,int sum){
    memset(dp,-1,sizeof(dp));
    if(n==0)
       return 0; 
   if(sum==0)
       return 1;
   
   if(dp[n-1][sum]!=-1)
        return dp[n-1][sum];
   
   if(arr[n-1]>sum)
       return dp[n-1][sum] = solve(arr,n-1,sum);
   
   if(arr[n-1]<=sum)
       return dp[n-1][sum] = solve(arr,n-1,sum-arr[n-1])||solve(arr,n-1,sum);
    return 0;

}

int main(){
    int n,sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%2!=0){
        cout<<"false";
        return 0;
    }
    if(solve(arr,n,sum/2)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
}
