class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
         int n=nums.size();
        int result=0;
        unordered_map<long,long> mp[n];
        for(int i=0;i<n;i++)//i limiting index kaha tak
        {
            for(int j=0;j<i;j++)//j always reset to zero initiating index
            {
                long diff=(long)nums[i]-nums[j];
                auto it=mp[j].find(diff);//map mai j se starting nikal lo
                int count_at_j=(it==end(mp[j]))?0:it->second;//agar nhi hai to 0 daal do warna jo count hai wo
                mp[i][diff]+=count_at_j+1;//diff key on the map jitne bhi aaye wo add kardo plus one jo nya mila
                result=result+count_at_j;

            }
        }
        return result;
    }
};