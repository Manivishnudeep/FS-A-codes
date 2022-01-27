/*
Seating Arrangement. 

There are two students in a class named '0' and '1'.
The height and width will be given by the teacher. 
There are many positions in the class to be occupied.
When the teacher asks the students to occupy the positions,
'1'  occupies all the postions and gives the turn to '0', to sit only in the middle(horizantally and vertically)

Help students to occupy the postions
There is a twist in this seating arrangement, if the height and width given by the teacher is a even integer , students dont occupy at all,in this case print -1 

Assume The height and width will be same  

input = 3
output =
101
000
101

input = 5
output =
11011
11011
00000
11011
11011

input = 7
output =
1110111
1110111
1110111
0000000
1110111
1110111
1110111
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%2==0){
        cout<<-1;
        return 0;
    }
    int cn=(n+1)/2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==cn || j==cn){
                cout<<0;
            }
            else{
                cout<<1;
            }
        }
        cout<<endl;
    }
}
