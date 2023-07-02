class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    map<int,int>mp ; 
        for(int i=0 ; i<numbers.size();i++)
        {
            mp[numbers[i]]= i ; 
        }
        for(int i=0 ;i<numbers.size() ;i++){
            int rem = target - numbers[i] ;
              if(mp.find(rem)!=mp.end() && i!=mp[rem]) 
              {
                  return { i , mp[rem]} ; 
              }
              
        }
        return {-1,-1} ; 
    }
};