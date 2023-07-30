class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
          unordered_map<int , int> mp ; 
        long long int ans =0 ,sum =0 ;
         mp[sum]++ ; 
        for(int i =0 ; i<arr.size();i++){
            sum+=arr[i] ; 
            if(mp.find(sum - k)!=mp.end())
                ans+=mp[sum- k] ;
            mp[sum]++ ;
            
        }
        return ans  ; 
    }
};