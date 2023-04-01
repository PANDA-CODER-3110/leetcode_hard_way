class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()<=0) return 0 ; 
   int n = arr.size(); 
map<int,int>mp ; 
        for(int i=0 ; i<n;i++)
        {
           mp[arr[i]]=1; 
        }
        
        for(auto it : arr)
        {
            if(mp.find(it-1)!=mp.end())
                mp[it] = 0 ;
        }
        
        int cnt =1 ;
        int ma = 1 ; 
        for(int i=0 ; i<n;i++)
        {
            if(mp[arr[i]]==1)
            {
                cnt =1 ; 
                int l = arr[i]; 
                while(mp.find(++l)!=mp.end())
                {
                    cnt++, ma = max(ma,cnt );
                }
            }
        }
        
        
        return ma  ; 
    }
};