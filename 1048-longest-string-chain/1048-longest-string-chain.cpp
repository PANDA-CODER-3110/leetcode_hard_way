class Solution {
   
public:
    bool possible(string&a , string&b){
        if(a.size()!=b.size()+1) return false ; 
        int first =0 ; int second =0 ; 
        while(first<a.size()){
            if(a[first]==b[second]){
                first++ ; 
                second++ ; 
            }
            else
                first ++ ; 
        }
        return (first == a.size() && second==b.size())? true : false ; 
    }
    static bool compareInterval(string &a , string &b)
    {
        return (a.size() < b.size()) ; 
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compareInterval) ; 
        int maxi =0 ; 
        int n = words.size() ; 
        vector<int>dp(n , 1) ; 
        for(int i =0 ; i<n ; i++){
            for(int j =0 ; j<i ; j++){
                if(possible(words[i] , words[j]) && dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j] ;
                }
            }
            maxi = max(maxi , dp[i]) ;
        }
        
        return maxi ; 
    }
};