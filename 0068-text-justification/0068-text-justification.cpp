class Solution {
public:
    string spacejustify(string str , int wid , int islast )
    {
        if(str.length()==wid)
            return str ; 
        
        int spaceInString =0 ; 
        for(int i=0 ; i<str.length() ;i++)
        {
            if(str[i]==' ')
                spaceInString++ ; 
        }
        
        int spaces = wid - str.length() ; 
        
        if(spaceInString==0 || islast==1)
          {
        str.insert(str.length(),spaces ,' ') ; 
            return str ; 
        }
      int eachslot = spaces /spaceInString ; 
        int leftover = spaces%spaceInString ; 
        
        
    for(int i=0 ; i<str.length();i++)
    {
        if(str[i]==' ' && (eachslot>0  || leftover>0)){
            int noofspaces = eachslot + ((leftover--)> 0 ?1 :0);
        str.insert(i , noofspaces ,' ') ; 
        i+=noofspaces ; 
    }
    }
        return str ; 
    }
   

    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>result ; 
     string output = words[0] ; 
        for(int i=1 ; i<words.size();i++){
            if(output.size()+words[i].size()+1<=maxWidth)
                output+=" "+words[i] ; 
            else
            {
                output = spacejustify(output , maxWidth , 0) ; 
                result.push_back(output) ; 
                output = words[i] ; 
            }
            
        }
         output = spacejustify(output , maxWidth , 1) ;
        result.push_back(output) ; 
        return result ; 
        
     }
};