class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        //topological sort can help me in iterating over all the persons who are richer than child so basically i can compare everytime and fill the right person there
        int n=quiet.size();
        vector<int> indegree(n,0), ans(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)ans[i]=i;//assume i is itself the ans which is true in some cases
        for(auto vec:richer){
            adj[vec[0]].push_back(vec[1]);
            indegree[vec[1]]++;
        }
        // push all the richest persons in the queue
        queue<int> pending;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)pending.push(i);
        }
    vector<int>dp ; 
        while(!pending.empty()){
            int u=pending.front();
            pending.pop();
            dp.push_back(u) ; 
            for(auto child : adj[u]){
                indegree[child]--;//dependency removal from parent
                if(indegree[child]==0)pending.push(child);//all the richer are explored
                if(quiet[ans[child]]>quiet[ans[u]]){// ans[u] is the person least quiet person than u being the richer or equal than it
                    ans[child]=ans[u];
                }
            }
        }
        for(auto it :dp)
        {
            cout<<it<<" " ; 
        }
        cout<<endl; 
        return ans;
    }
};