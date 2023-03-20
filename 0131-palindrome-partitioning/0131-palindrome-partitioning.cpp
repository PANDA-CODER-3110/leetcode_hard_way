class Solution {
public:
    
    
    // here we are creating the[partitiions at regular interals and storing the result in a temp variable and then after checking that the pat before the paritiion is a palindrome or not and the part after the partitiion is checked by the recursive line 
    //----> solve(para , opara ,para )  the recursive t line , and then backtracking is done by pop backing the last puhshed eleement and then the next string is checked by incresing the pos of partition 
    vector<vector<string>>ans;
    void solve(string&s ,int index ,  vector<string>&temp )
    {       
        if(index == s.size())
            ans.push_back(temp); 
        else
        {
           for(int i=index;i<s.size();i++)
           {
               if(ispalindrome(s,index,i))
               {
                   temp.push_back(s.substr(index,i-index+1)); 
                   solve(s,i+1,temp ); 
                       temp.pop_back(); 
               }
           
           }
        }
        
    }
//    void partition(string& s, int start, vector<string>& path) {
        
//         if (start == s.size()) {
//             ans.push_back(path);
//         } else {
//             for (int i = start; i < s.size(); i++) {
//                 if (ispalindrome(s, start, i)) {
//                     path.push_back(s.substr(start, i - start + 1));
//                     partition(s, i + 1, path);
//                     path.pop_back();
//                 }
//             }
//         }
//     }

    bool ispalindrome(string s , int start , int end )
    {
        while(start <end)
        {
            if(s[start++]!=s[end--]) return false ; 
        }
        return true ; 
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp ;
        
        solve(s,0 , temp);
        return ans ; 
        
    }
};