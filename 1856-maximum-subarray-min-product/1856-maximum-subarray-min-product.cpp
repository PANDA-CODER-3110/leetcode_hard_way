class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<long>preSum, left(nums.size(), -1), right(nums.size(), nums.size());
     int n = nums.size();
     preSum.push_back(0);
	 
	 //Getting perfix sum of given array to reduce complexity by avoiding recalculation 
     for (int i = 0; i < nums.size(); i++)
        preSum.push_back(preSum.back() + nums[i]);

    // Storing previous smaller element index in left array
	 stack<int>st;
    for(int i =0 ; i<n ; i++){
        while(!st.empty() && nums[st.top()]>nums[i])
        {
            right[st.top()] = i ; 
            st.pop() ; 
        }
        st.push(i) ; 
    }
        while(!st.empty()){
            st.pop() ; 
        }
        
        for(int i = n-1 ; i>=0 ; i--)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
        {
            left[st.top()] = i ; 
            st.pop() ; 
        }
        st.push(i) ;
        }
        
           for(auto it : left)
            cout<<it<<" "; 
        cout<<endl; 
        for(auto it : right)
            cout<<it<<" "; 
  long ans = 0, mod = 1e9 + 7;

//finally calculating the contribution of each element
  for (int i = 0; i < nums.size(); i++) {
  long t = (preSum[right[i]] - preSum[left[i] + 1]) * nums[i];
  ans = max(ans, t);
  }

  return ans % mod; 
    }
};