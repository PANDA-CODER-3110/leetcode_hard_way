class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>>pq ; 
       int res ;  
        int i =0 ; 
        while(i<nums.size())
        {
            if(pq.size()==k && pq.top()<nums[i]) 
                pq.pop() ; 
            if(pq.size()<k)
            {
                pq.push(nums[i]) ; 
            }
            i++ ; 
        }
      
        return pq.top();
    }
};