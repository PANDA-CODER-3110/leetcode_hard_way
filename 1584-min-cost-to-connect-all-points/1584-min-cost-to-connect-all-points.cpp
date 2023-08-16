class ds{
    public:
   vector<int>rank;
   vector<int>parent;
   
   int find_parent(int v){
       if(v==parent[v]){return v;}
       return parent[v]=find_parent(parent[v]);
   }
   
   void unionn(int u,int v){
       int ulti_u=find_parent(u);
       int ulti_v=find_parent(v);
       
       if(ulti_u==ulti_v){return;}
       if(rank[ulti_u]>rank[ulti_v]){
           parent[ulti_v]=ulti_u;
       }
       else if(rank[ulti_u]<rank[ulti_v])
       {
           parent[ulti_u]=ulti_v;
       }
       else{
           parent[ulti_u]=ulti_v;
           rank[ulti_u]++;
       }
   }
   ds(int V){
       rank.resize(V);
       parent.resize(V);
       for(int i=0;i<V;i++)
	    {
	       parent[i]=i;
	    }
   }
};
class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {   int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({wt,{i,j}});
            }
        }
        sort(edges.begin(),edges.end());
        ds D(points.size());
        int cost=0;
        for(auto it:edges)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(D.find_parent(u) !=D.find_parent(v)){
                cost +=wt;
                D.unionn(u,v);
            }
        }
    return cost;}
};