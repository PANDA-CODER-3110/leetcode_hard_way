class Solution {
public:
   vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>res;
        unordered_set<int>hash;
        vector<bool>isPrime(n+1,true);
        for(int i=2;i*i<=n;i++)
        {
            if(isPrime[i] == true)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    isPrime[j] = false;
                }
            }
        }
        for(int i=2;i<=n;i++)
        {
            if(isPrime[i] == true)
            {
                if(hash.find(n-i) != hash.end())
                { 
                    res.push_back({n-i,i});
                }
                if(2 * i == n)
                    res.push_back({i,i});
                hash.insert(i);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};