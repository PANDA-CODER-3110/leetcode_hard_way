struct Node{
    Node* links[26] ; 
    bool end = false ; 
    
    void puts(char ch){
        Node* node = new Node() ; 
        links[ch-'a'] = node ; 
     }
    
    bool contains(char ch){
         return (links[ch-'a']!=NULL) ;
    }
       
    
    Node* get(char ch){
        return links[ch-'a'] ; 
    }
    
    void setEnd()
    {
        end = true ; 
    }
    
    bool isEnd(){
        return end ; 
    }
    
};

class Trie {
    private:Node*root ; 
public:
    Trie() {
        root = new Node() ; 
    }
    
    void insert(string word) {
        Node* cur = root ; 
        for(auto ch :word){
            
           if(!cur->contains(ch)){
               cur->puts(ch) ; 
           }
            cur=cur->get(ch) ; 
        }
        cur->setEnd() ;
        
        
    } ;
    
    bool searchutil(string word , bool ans){
        Node* cur = root ;
        for(auto ch : word){
            if(!cur->contains(ch)){
                return false ; 
                
            }
            cur=cur->get(ch) ; 
        }
        return (ans?cur->isEnd():true); 
     }
    
    bool search(string word) {
        return searchutil(word , true) ;
    }
    
    bool startsWith(string prefix) {
       return searchutil(prefix , false ) ; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */