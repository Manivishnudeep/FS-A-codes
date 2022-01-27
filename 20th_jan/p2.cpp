/*

Ramu is given an array of numbers now he has to check for a super square matrix in the given array.

A super square matrix is a matrix such that every row sum, every column sum, and both
diagonal sums are all equal. 

The integers in the magic square do not have to be distinct. 
Every 1 x 1 grid is trivially a super square matrix 

Given an m x n integer grid , return the size (i.e., the side length k ) of the largest super square matrix that can be found
within this grid.



Example 1:

Input = 
4 5
7 1 4 5 6
2 5 1 6 4
1 5 4 3 2
1 2 7 3 4
Output: 3

Explanation: 

From the above array we have the following super square matrix of size 3 
5 1 6 
5 4 3
2 7 3 



The largest super square matrix has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12


*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    
    vector<vector<int>>r(100,vector<int>(100,0));
    vector<vector<int>>c(100,vector<int>(100,0));
    vector<vector<int>>d1(100,vector<int>(100,0));
    vector<vector<int>>d2(100,vector<int>(100,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            r[i][j]=mat[i-1][j-1]+r[i][j-1];
            c[i][j]=mat[i-1][j-1]+c[i-1][j];
            d1[i][j]=mat[i-1][j-1]+d1[i-1][j-1];
            d2[i][j]=mat[i-1][j-1]+d2[i-1][j+1];
        }
    }
    
    int ans=1;
    for(int k=1;k<=min(n,m);k++){
        for(int i=1;i<=n-k;i++){
            for(int j=1;j<=m-k;j++){
                set<int>s;
                int sum1=d1[i+k][j+k]-d1[i-1][j-1];
                int sum2=d2[i+k][j]-d2[i-1][j+k+1];
                s.insert(sum1);
                s.insert(sum2);
                for(int t=0;t<=k;t++){
                    int s1=(r[i+t][j+k]-r[i+t][j-1]);
                    s.insert(s1);
                    int s2=c[i+k][j+t]-c[i-1][j+t];
                    s.insert(s2);
                }
                if(s.size()==1){
                    ans=max(ans,k+1);
                }
            }
        }
    }
    cout<<ans;
}
