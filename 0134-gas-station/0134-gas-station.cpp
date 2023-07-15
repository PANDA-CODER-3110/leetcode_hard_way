class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() ; 
        int  bal=0 , def =0 ,start=0; 
        for(int i=0 ; i<n;i++)
        {
            bal+= gas[i] - cost[i] ; 
            if(bal<0)
            {
                def+=bal ; 
                start = i+1 ; 
                bal=0 ; 
            }
        }
         return bal+def>=0?start:-1 ; 
    }

};