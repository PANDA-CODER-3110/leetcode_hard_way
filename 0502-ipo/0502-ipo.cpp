class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         vector<pair<int,int>> list;
        int i=0;
        for(i=0;i<profits.size();i++)
            list.push_back(make_pair(profits[i], capital[i]));

        sort(list.begin(),list.end());

        for(int lun=1;lun<=k;lun++)
        {
            for(i=list.size()-1;i>=0;i--)
                if(list[i].second<=w)
                {
                    w += list[i].first;
                    list.erase(list.begin()+i);
                    break;
                }

            if(i==-1)
                break;
        }
        return w;
    }
};