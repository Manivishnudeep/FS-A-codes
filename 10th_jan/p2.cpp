/*
A Group of Monsters has few powers. 
The powers are represented in numbers both positive and negative. 
Each Member of the monster prays to get some power. 
God sanctions only one member of the Monster Group. 
The power can be performed only once on only one member of the monster. 
God will multipy the monster power with the same power. 
After  performing the above action, a sub-group of monsters check the power they have.
We have to now see which sub-group has the highest power. Print the Highest Sub-Power.


The first line of input contains the powers of the monsters. 

input = 4 -1 -5 -3
output = 28

The power operation is performed on the third monster, -5 * -5 which is 25 

Now the sub group with highest power is 4+(-1)+25 = 28 

*/
#include<bits/stdc++.h>
using namespace std;
int maxi(vector<int> v){
    sort(v.begin(),v.end());
    int n=v.size();
    if(pow(v[n-1],2)<pow(v[0],2)){
        return v[0];
    }
    else{
        return v[n-1];
    }
}
int tmax(vector<int> v){
    vector<int>::iterator it;
    it= find(v.begin(),v.end(),maxi(v));
    v[it-v.begin()]=pow(v[it-v.begin()],2);
    int msf=0, cm=INT_MIN;
    int count=0;
    for(int i: v){
    	msf+= i;
        if(msf<0) msf=0;
        if(msf>cm) cm=msf;
    }
    
    return cm;
}
int main(){
    vector<int> v;
    while(1){
        int k;
        cin>>k;
        v.push_back(k);
        if(cin.peek()=='\n'){
            break;
        }
    }
    cout<<tmax(v);
}
