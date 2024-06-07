class Solution {
public:
    string check(string s, vector<string> &dict){
        int n = dict.size();
        string a = "-1";
        for(int i=0;i<n;i++){
            int m = dict[i].size();
            //cout<<s.substr(0,m)<<endl;
            if(s.substr(0,m) == dict[i]){
                string d = dict[i];
                if(a == "-1" || d.length()<a.length()){
                    a = d;
                }
            }
        }
        return a;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";
        int n = sentence.length();
        string s = "";
        int i=0;
        while(i<n){
            if(sentence[i] != ' '){
                s += sentence[i];
                i++;
            }
            else{
                //cout<<check(s,dictionary)<<endl;
                if(check(s,dictionary) != "-1"){
                    ans += check(s,dictionary);
                }
                else{
                    ans += s;
                }
                ans += " ";
                s = "";
                i++;
            }
        }
        if(check(s,dictionary) != "-1"){
            ans += check(s,dictionary);
        }
        else{
            ans += s;
        }
        return ans;
    }
};