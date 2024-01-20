class Solution {
public:
    long long MOD = 1e9+7 ; 
    int sumSubarrayMins(vector<int>& arr) {
      int N = arr.size() ; 
         vector<int> left(N,-1);
        vector<int> right(N,N);
        
        stack<int> s;
        for(int i=0;i<N;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                left[i]=s.top();
            }
            s.push(i);
        }
        
        s=stack<int>();
        for(int i=N-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(!s.empty()){
                right[i]=s.top();
            }
            s.push(i);
        }
        
        long long res=0;
        for(int i=0;i<N;i++){
            int L=i-left[i];
            int R=right[i]-i;
            long long prod = (L*R)%MOD ; 
            prod = (prod*arr[i])%MOD;
            res=(res+prod)%MOD ;   // L+1 to R-1 is the range where arr[i] is minimum you see
            res%=1000000007;
        }
        return res;
    }
};