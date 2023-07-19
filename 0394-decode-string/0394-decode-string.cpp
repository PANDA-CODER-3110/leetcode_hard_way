class Solution {
public:
    string decodeString(string s) {
         stack<char>st;
        for(auto c : s){
            if(c!=']'){
                st.push(c);
            }
            else{
                string str = "";
                while(st.top()!='['){
                    str = st.top()+str;
                    st.pop();
                }
                st.pop();
                string times = "";
                while(!st.empty() && isdigit(st.top())){
                    times = st.top() + times;
                    st.pop();
                }
                // cout << times << " ";
                for(int i = 0; i<stoi(times); i++){
                    for(auto c : str)
                        st.push(c);
                }
                str.clear();
                times.clear();
            }
        }
        string result = "";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};