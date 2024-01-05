//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  
  string ans="";
  
  int n = src.length();
  
 int cnt=1;
 
  for(int i=0;i<n-1;i++){
     if(src[i]==src[i+1]) cnt++;
      else {
          ans += src[i] + to_string(cnt);
          cnt=1;
      }
  }
  
  ans += src[n-1] + to_string(cnt);
  
  return ans;
}     
 
