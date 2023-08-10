class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& nums) {
        vector<int>ans(nums.size() , 0) ; 
        stack<int>st ; 
        for(int i = nums.size() - 1; i>=0 ; i--)
        { int cnt =0  ; 
            while(!st.empty() && nums[i] > nums[st.top()] )
            {
                cnt++ ; 
                st.pop() ; 
            }
         cnt+=(!st.empty())  ; 
            ans[i] = cnt ; 
         st.push(i) ; 
         
        }
        
        
        return ans ; 
        
        
    }
    
    
    
    
};