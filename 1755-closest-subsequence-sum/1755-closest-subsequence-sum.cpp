class Solution {
public:

    void f(int ind, int sum,int end, vector<int> &nums, vector <int> &v ){
        if(ind == end){
            v.push_back(sum);
            return;
        }

        f(ind+1,sum + nums[ind],end,nums,v);
        f(ind+1,sum,end,nums,v);
    }



    int minAbsDifference(vector<int>& nums, int goal) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        int n = nums.size();
        vector <int> left, right;

        f(0,0,n/2,nums,left);
        f(n/2,0,n,nums,right);

        sort(right.begin(),right.end());

        int ans = INT_MAX;
        for(auto &l : left){
            auto r = lower_bound(right.begin(),right.end(),goal - l);
            if(r != right.end()){
                ans = min(ans,abs(goal - l - *r));
            }

            if(r != right.begin()){
                auto prev = r;
                prev--;
                ans = min(ans,abs(goal - l - *prev));
            }
            
            if(ans == 0 )   return ans;
        }

        return ans;
    }
};