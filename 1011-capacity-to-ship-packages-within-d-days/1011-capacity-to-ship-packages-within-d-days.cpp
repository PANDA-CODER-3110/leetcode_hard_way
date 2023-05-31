class Solution {
public:
bool can(int mid,vector<int>& weights, int days) {
       int count = 1, sum = 0 ;
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > mid) {
                count++;
                sum = weights[i];
            }
        }
       return (count<=days) ; 
}
    int shipWithinDays(vector<int>& weights, int days) {
        int start =  *max_element(weights.begin(), weights.end()) , end =accumulate(weights.begin(),weights.end(),end)  ; 
        int ans = INT_MAX ; 
        while(start<=end)
        {
            int m = (start+end)/2;
            if(can(m,weights,days))
            {
                 end  = m-1  ; 
                     ans = m ; 
                   
            }
            else
            {
                start = m+1 ;
            }
        }
        return start  ; 

    }
};