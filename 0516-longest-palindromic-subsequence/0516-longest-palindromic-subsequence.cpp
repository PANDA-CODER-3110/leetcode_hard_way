class Solution {
public:
    int longestPalindromeSubseq(string s1) {
          string s2 =s1;
        reverse(s2.begin(),s2.end());
           int x =s1.length();
      
         int y =s2.length();
  
       vector<int>prev(y+1,0);
        vector<int>temp(y+1 , 0) ; 
        //return solve(x,y,s1,s2,t);
      
      for(int i=1;i<x+1;i++)
      {
          for(int j=1;j<y+1;j++)
          {
               if(i==0 || j==0)
              prev[j]=0;
              
             else if(s1[i-1]==s2[j-1])
             temp[j]=1+prev[j-1];
             
             else
             temp[j]=max(prev[j],temp[j-1]);
          }
          prev = temp ; 
      }
          
      return prev[y];
    }
        
    
};