/*

Ragav is working with strings, which contain digits from [0-9] only.
he has to find if given string is a downgraded string or not.

A string is said to be a downgraded string, if the string follows the below rules:
	- Divide the string S into two or more substrings, like sub[0],sub[1], sub[2],..,sub[n-1]. 
	  If you append all the substrings should result in S,sub[0]+sub[1]+ sub[2]+..+sub[n-1] = S
	  
	- The numeric values of the substrings should be in decreasing order.
	  i.e., sub[0] > sub[1] > .. > sub[n-1].
	- The difference between each consecutive pair should be 1 only.
	  i.e., sub[0]-sub[1] = sub[1]-sub[2] = .. = sub[n-2]-sub[n-1] = 1.

Your task is to help Ragav to check the given numeric string is downgraded string or not. 
If yes, print "true", Otherwise print "false".

Input Format:
-------------
A String, numeric word.

Output Format:
--------------
Print a boolean result.


Sample Input-1:
---------------
004567

Sample Output-1:
----------------
false

Explanation:
------------
Numeric Word can be divided as follows: "004","5","6","7"
Given word is not a downgraded string. 


Sample Input-2:
---------------
1201100010

Sample Output-2:
----------------
true

Explanation:
------------
Numeric Word can be divided as follows: "12","011","00010"
The numeric value of substrings are: 12, 11, 10


Sample Input-3:
---------------
5040301

Sample Output-3:
----------------
false

Explanation:
------------
Numeric Word can be divided as follows: "5","04","03","01"
The numeric value of substrings are: 5,4,3,1
Rule-1 and Rule-2 are followed but Rule-3 is not followed.



Sample Input-4:
---------------
99999998

Sample Output-4:
----------------
true

Explanation:
------------
Numeric Word can be divided as follows: "9999","9998".
*/
#include<bits/stdc++.h>
using namespace std;
bool dfs(int index,long long first,string& str){
	if (index==str.length())
		return true;
	for (int j=index;j<str.length();j++){
		long long second=stoll(str.substr(index,j-index+1));
		if(second+1==first && dfs(j+1,second,str))
			return true;
		else if(second>first)
			return false;
	}
	return false;
}
int main(){
    string s;
	cin>>s;
	long long n=s.length();
	while(s[0]=='0'){
	    s.erase(0,1);
	}
	if(n%2==0){
		n=n/2;
    }
	else{
		n=(n/2)+1;
	}
	long long first;
	for (int i=0;i<n;i++) {
		try{
		    first=stoll(s.substr(0,i+1));
		}
		catch(...){
		    cout<<"false";
		    return 0;
		}
		if (dfs(i+1,first,s)){
		    cout<<"true";
		    return 0;
		}
	}
	cout<<"false";
}
