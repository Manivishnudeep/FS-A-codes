/*Amazon fire tv stick keyboard wanted to be operated on number pad. 
You will be given the below pad. 
You are supposed to print all possible words in alphabetic order for a given number (0-9)

	1		2		3
		   abc	   def
		 
	4		5		6
   ghi             jkl     mno
  
	7		8		9
  pqrs           tuv    wxyz
	
	*		0		#


You will be given a string S which contains (2-9)  only  
For example: S = "3", then the possible words are "d", "e", "f".

Input Format:
-------------
String(2-9)

Output Format:
--------------
Print the list of words in alphabetical order


Sample Input-1:
---------------
2

Sample Output-1:
----------------
a b c


Sample Input-2:
---------------
24

Sample Output-2:
----------------
ag ah ai bg bh bi cg ch ci
*/
#include<bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
void comb(vector<char>v[],string s, string str, int index, int n)
{
	if (index==n){
		cout<<str<<" ";
		return;
	}
	int t =s[index]-'0';
	int len=v[t].size();
	for (int i=0;i<len;i++) {
		comb(v,s,str+v[t][i],index+1,n);
	}
}

int main()
{
	vector<char> v[] =
	{
	    {},{},
		{'a','b','c'},
		{'d','e','f'},
		{'g','h','i' },
		{'j','k','l' },
		{'m','n','o' },
		{'p','q','r','s'},
		{'t','u','v'},
		{'w','x','y','z'}
	};
	string input;
	cin>>input;
	int n=input.length();
	string str="";
	comb(v,input,str,0,n);
}

