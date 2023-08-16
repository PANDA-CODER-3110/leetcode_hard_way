class UnionFind{
   vector<int> parent;

   public:
   UnionFind(int n) {
       for(int i=0; i<n; i++){
           parent.push_back(i);
       }
   }

   int find(int x){
       int root = x;
       while(root != parent[root])
       root = parent[root];

       while(x != root){
           int t = parent[x];
           parent[x] = root;
           x = t;
       }
       return root;
   }

   void union_(int& x, int& y){
       int xSet = find(x);
       int ySet = find(y);

       if(xSet == ySet) return;

       if(xSet < ySet) parent[ySet] =xSet;
       else parent[ySet] = xSet;
   }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        UnionFind obj(n);
        int count =0;
        for(int i=0; i<n; i+=2){
            obj.union_(row[i], row[i+1]);
        }

        for(int i=0; i<n; i+=2){
            int set1 = obj.find(i);
            int set2 = obj.find(i+1);

            if(set1 == set2) continue;
            count++;
            obj.union_(set1, set2);
        }
        return count;
    }
};