class Solution {
public:
    int validSubarraySize(vector<int>&h, int t) {
           vector<int> l(h.size()),r(h.size());
        stack<int> st;
        for(int i=0;i<h.size();i++){                               // for smaller element on left
            while(!st.empty() && h[st.top()]>=h[i]) st.pop();
            if(st.empty()) l[i]=-1;
            else l[i]=st.top();
            st.push(i);
        }
        int n=h.size();
        st=stack<int>();
        for(int i=n-1;i>=0;i--){                             // for smaller element on right
            while(!st.empty() && h[st.top()]>=h[i]) st.pop();
            if(st.empty()) r[i]=n;
            else r[i]=st.top();
            st.push(i);
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            int k = (r[i]-l[i]-1);       // length for which the current element is smaller
            double z = (1.0*t)/(1.0*k);       
            if(1.0*h[i]>z) return k;         // if condition satisfies for smaller element then just return length
        }
        return -1;
    }
};