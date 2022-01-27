/*
There are N players, playing a game.

You are given the scores of the N players as scores[] array,
where i-th player score is score[i].

You are given P chances to modify the score of the players.

In each chance you can modify the score of i-th player as follows:
	- You are allowed increment the score of i-th player by 1.

You have to perform these increments, in order to maximize the occurances of any score.

Your task is to maximize occurances of a score, after utlizing atmost P chances.

Input Format:
-------------
First line of input consists of the scores followed by the number of chances(P)

Output Format:
--------------
Print an integer, maximum occurances of a score!


Input = 1 2 4 
5
Output = 3

Explanation: Increment the first score three times and the second score two times to make scores = [4,4,4].
4 has a maximum of 3 occurances



Example 2:
Input  = 1 4 8 13
5
Output: 2

Explanation: There are multiple optimal solutions:

- Increment the first score three times to make scores = [4,4,8,13]. 4 has a maximum occurance of 2.
- Increment the second score four times to make scores = [1,8,8,13]. 8 has a maximum occurance of 2.
- Increment the third score five times to make scores = [1,4,13,13]. 13 has a maximum occurance of 2.


*/
#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int maxf(vector<int>& arr, int k) {
        int n=arr.size(),sum=0;
        sort(arr.begin(),arr.end());
        int l=0,r=0;
        int maxi=INT_MIN;
        while(r<n)
        {
            sum +=arr[r];
            while(l<n &&((arr[r]*(r-l+1))>(sum + k)))
            {
                sum-=arr[l];
                l++;
            }
            maxi=max(maxi,(r-l+1));
            r++;
        }
        return maxi;
}
int main(){
    vector<int> v;
    while(1){
        int i;
        cin>>i;
        v.push_back(i);
        if(cin.peek()=='\n'){
            break;
        }
    }
    int k;
    cin>>k;
    cout<<maxf(v,k);
}
    
