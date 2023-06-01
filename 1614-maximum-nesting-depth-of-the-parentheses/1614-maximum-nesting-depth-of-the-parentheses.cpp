class Solution {
public:
    int maxDepth(string s) {
        int m=0;

        int count=0;

        int n=s.size();

        for(int i=0;i<n;i++){

            if(s[i]=='('){

                count+=1;

            }

            if(s[i]==')'){

                count-=1;

            }

            m=max(count,m);

        }

        return m;
    }
};