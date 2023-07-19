class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
          unordered_map<string,int> hash;
        for (string i : bank)
        {
            hash[i]++;
        }

        queue<string> q;
        int ans = 0;
        q.push(startGene);
        unordered_map<string,int> vis;
        vis[startGene] = 1;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                string curr = q.front();q.pop();

                if (curr == endGene)
                {
                    return ans;
                }
                else
                {
                    for (int i = 0;i<8;i++)
                    {
                        vector<char> v = {'A','C','G','T'};
                        for (char ch : v)
                        {
                            //if (curr[i] == ch) continue;

                            string temp = curr;
                            temp[i] = ch;
                            if (vis.find(temp) == vis.end() && hash.find(temp) != hash.end())
                            {
                                vis[temp] = 1;
                                q.push(temp);
                            }
                            
                        }
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};