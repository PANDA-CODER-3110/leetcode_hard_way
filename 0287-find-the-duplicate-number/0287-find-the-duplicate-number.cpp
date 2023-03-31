class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start =0  , end = nums.size()-1 ; 
        while(start+1<end)
        {
            int mid = (start+end)/2; 
            int cnt =0 ; 
            for(auto it : nums)
            {
                if(it<=mid)
                    cnt++;
            }
            if(cnt<=mid)
                start = mid ; 
            else
                end = mid ; 
        }
        
        return end  ; 
    }
};