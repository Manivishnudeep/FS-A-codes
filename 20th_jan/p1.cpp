/*

Vikram a third class boy plays with a numbers, he will be given a number(n) and 
he starts writing the numbers on each line until he reaches the number(n).

Write the code and verify if the vikrams writing of the number is same or not. 

Assume n>=1


input = 5
output =
1
1 2
3 5 8
13 21 34 55
89 144 233 377 610


input = 4
output = 
1
1 2
3 5 8
13 21 34 55
*/
#include<bits/stdc++.h>
using namespace std;
void fib(int arr[], int n) 
{ 
    arr[0]=1; 
    arr[1]=1; 
    for (int i=2;i<=n;i++){ 
        arr[i]=arr[i-1]+arr[i-2];
    }
} 
int main(){
    int n;
    cin>>n;
    int r=n*(n+1)/2,k=0;
    int arr[r+1];
    fib(arr,r);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<arr[k]<<" ";
            k++;
        }
        cout<<endl;
    }
}
