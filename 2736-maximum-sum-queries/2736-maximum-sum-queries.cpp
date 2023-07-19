class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> ret;
        vector<pair<int,int>> nums;
        for(int i=0;i<nums1.size();i++)
            nums.push_back(make_pair(nums1[i],nums2[i]));
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-2;i>=0;i--)
            if(nums[i].second<=nums[i+1].second)
                nums.erase(nums.begin()+i);
        for(auto q:queries)
        {
            int smax = -1;
            for(int i=nums.size()-1;i>=0;i--)
            {
                if(nums[i].first<q[0])
                    break;
                if(nums[i].second<q[1])
                    continue;
                smax = max(smax, nums[i].first+nums[i].second);
            }
            ret.push_back(smax);
        }
        return ret;
    }
};