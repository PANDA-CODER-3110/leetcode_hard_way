class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       sort(strs.begin(),strs.end());
        int N = strs.size() ; 
        
        //cout<<arr[0]<<arr[N-1]<<endl;
        string s ;
        for(int i=0;i<strs[N-1].size();i++)
        {
            if(strs[0][i]==strs[N-1][i])
            s.push_back(strs[N-1][i]);
           else break ;
        }
    
        return s;
    }
};