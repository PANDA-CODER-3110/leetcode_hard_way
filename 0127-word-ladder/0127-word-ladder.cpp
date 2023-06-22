class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& w) {
        queue<pair<string,int>>q; 
        q.push({beginWord,1}) ; 
        set<string>st(w.begin(),w.end()) ; 
        st.erase(beginWord) ;
        while(!q.empty())
        {
            string word = q.front().first ;
            cout<<word<<" "; 
             int steps = q.front().second ; 
            q.pop() ; 
            if(word==endWord)
                return steps  ; 
            for(int i=0 ; i<word.size();i++)
            {
                char pl = word[i] ; 
                for(char ch = 'a'  ; ch<='z';ch++)
                {
                    word[i]= ch ; 
                    if(st.find(word)!=st.end())
                    {      
                        st.erase(word) ;
                        q.push({word,steps+1}) ; 
                         
                    }
                }
                word[i] = pl  ; 
            }
        }
        return 0 ; 
        
    }
};