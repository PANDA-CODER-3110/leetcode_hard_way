class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
         vector<int>ans;
       
        sort(nums.begin(), nums.end());
        
        
        for(int i=1;i<nums.size(); i++){
            if((nums[i-1]^nums[i])==0){
                ans.push_back(nums[i]);
            }
            
        }
        
       set<int>st;
        
       
        for(auto i:nums){
            st.insert(i);
        }int count=1;
        for(auto i:st){
            if(i==count){
                count++;
            }else{
                break;

            }
        }
        ans.push_back(count);
        
        return ans;
       
        
    }
};