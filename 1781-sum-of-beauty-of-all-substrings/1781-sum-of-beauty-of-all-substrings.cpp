class Solution {
public:
    int beauty(int freq[])
    {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                min_val = min(min_val, freq[i]);
                max_val = max(max_val, freq[i]);
            }
        }
        return (max_val-min_val);
    }
    
    
    int beautySum(string s) 
    {
        //Code here
        int sum = 0;
        for(int i=0;i<s.length();i++)
        {
            int freq[26] = {0};
            for(int j=i;j<s.length();j++)
            {
                freq[s[j]-'a']++;
                sum += beauty(freq);
            }
        }
        return sum;
    }


};