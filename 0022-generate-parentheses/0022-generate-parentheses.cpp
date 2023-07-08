class Solution {
public:
   void generate(int open , int close , string s , int n ,vector<string>&ans )
    {  
        if(s.size()==2*n)ans.push_back(s) ; 
        if(open<n)
        {
            generate(open+1 , close , s+'(' , n,ans) ; 
        }
        if(close<open)
        generate(open , close+1 , s+')',n,ans)  ;
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
          generate(0,0,"",n,ans);
            return ans ; 
    }
};