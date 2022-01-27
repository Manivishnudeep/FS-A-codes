/*
Ramu is a milk supplier. He has only two aluminium cups of capacity m and n litres. 
Using these two cups only, he can measure the milk. 
He has to supply exactly P litres of milk

To measure the milk, the operations allowed are:
	- Fill one of the cups completely with milk.
	- Empty the other cup.
	- Pour milk from one cup into another cup till it fills completely,
	 or the first cup itself is empty.
	 
Such that, at the end one or both cups contains P litres of the milk.
	
Please help Ramu, to check whether P litres of milk can be measured
using the two cups or not.

Input Format:
-------------
3 space separated integers, m, n and P.

Output Format:
--------------
Print a boolean value.


input=3 5 4
output=true


input=2 4 5
output=false
*/
#include<bits/stdc++.h>
using namespace std;
bool solve(int m,int n,int p){
    if(m+n<p){
        return false;
    }
    
    if((p% __gcd(m,n))==0){
        return true;
    }
    return false;
}
int main(){
    int m,n,p;
    cin>>m>>n>>p;
    if(solve(m,n,p)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}

