/*

Shankar is given a set of N pluck cards, each card labelled with a number on it, and he is also given a difference value as ‘D’.
Now Shankar has to find out the length of the largest arithmetic set ‘S’.

A subset is called as arithmetic set, iff the difference between the numbers on any two adjacent cards is same as D.

A subset can be derived from the set of N pluck cads by deleting some or no cards without changing the order of the remaining cards.

Input Format:
------------- 
Line-1: Two space separated integers N, D, number of cards, difference.
Line-2: N space separated integers, numbers on the set of cards.

Output Format:
--------------
Print an integer, length of longest arithmetic subset.


input=6 2
1 2 3 4 6 8
output=4

Input=8 -2
8 1 2 6 5 4 2 0 
output=5
*/
//using map
#include<bits/stdc++.h>
using namespace std;
int ap(int arr[],int n,int d){
    map<int,int> mp;
    int count=1;
    for(int i=0;i<n;i++){
        mp[arr[i]]=mp[arr[i]-d]+1;
        count=max(count,mp[arr[i]]);
    }
    return count;
}
int main(){
    int n,d;
    cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<ap(arr,n,d);
}

//using arr
#include<bits/stdc++.h>
using namespace std;
int ap(int arr[],int n,int d){
    int mp[1000]={0};
    int count=1;
    for(int i=0;i<n;i++){
        mp[arr[i]]=mp[arr[i]-d]+1;
        count=max(count,mp[arr[i]]);
    }
    return count;
}
int main(){
    int n,d;
    cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<ap(arr,n,d);
}

