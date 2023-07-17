class Solution {
public:
    int evalRPN(vector<string>& t) {
         stack<int> st;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == "+" || t[i] == "-" || t[i] == "*" || t[i] == "/") {
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();

                if (t[i] == "+") {
                    st.push(op2 + op1);
                } else if (t[i] == "-") {
                    st.push(op2 - op1);
                } else if (t[i] == "*") {
                    st.push(op2 * op1);
                } else {
                    st.push(op2 / op1);
                }
            } else {
                st.push(stoi(t[i]));
            }
        }
        return st.top();
    }
};