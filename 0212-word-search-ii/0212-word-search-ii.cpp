struct Node{

    Node* links[26];
    bool flag=false;

    bool containsKey(char ch)
    {
        return links[ch-'a'] != NULL;
    }

    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void setEnd()
    {
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

void solve(int i,int j,set<string>&res,string temp,vector<vector<char>>& b,vector<vector<int>>&v)
{
    if(temp.size() > 10 || v[temp.size() - 1][temp.back() - 'a'] == 0)
    return;

    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};

    for(int k=0;k<4;k++)
    {
        int newr=i+dx[k];
        int newc=j+dy[k];
        if(newr < 0 || newc < 0 || newr == b.size() || newc == b[0].size() || b[newr][newc]=='.')
        continue;
        
        char ch=b[newr][newc];
        b[newr][newc]='.';
        temp+=ch;
        solve(newr,newc,res,temp,b,v);
        temp.pop_back();
        b[newr][newc]=ch;
    }
    res.insert(temp);
return;
}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        vector<vector<int>>v(11,vector<int>(26,0));
        for(int i=0;i<w.size();i++)
        {
            for(int j = 0;j < w[i].length(); j++)
            {
                v[j][w[i][j] - 'a']++;
            }
        }
        set<string>res;
        vector<string>ans;
        // store all words in res array
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<b[0].size();j++)
            {
                string send;
                send+=b[i][j];
                b[i][j]='.';
                solve(i,j,res,send,b,v);
                b[i][j]=send[0];
            }
        }
        
        // store all words in Trie 
        Node* root=new Node();
        for(auto &i:res)
        {
            Node* node=root;
            string word=i;
            for(int j=0;j<word.length();j++)
            {
                if(!node->containsKey(word[j]))
                {
                    node->put(word[j],new Node());
                }
                node=node->get(word[j]);
            }
            node->setEnd();
        }

        // search word in the trie (just search prefix if prefix exist word will exist)
        for(int j=0;j<w.size();j++)
        {
            Node* node=root;
            string& word=w[j];
            bool ok=true;
            for(int i=0;i<word.length();i++)
            {
                if(!node->containsKey(word[i]))
                {
                    ok=false;
                    break;
                }
                node=node->get(word[i]);
            }
            if(ok)
            {
                ans.push_back(word);
            }
        }
    return ans;
    }
};