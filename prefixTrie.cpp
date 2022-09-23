class Trie {
public:
    struct Node{
        Node* links[26];
        bool flag = false;
        
        bool containsKey(char ch){
            if(links[ch - 'a'] == NULL){
                return false;
            }
            return true;
        }
        
        void put(char ch , Node *newNode){
            links[ch - 'a'] = newNode;
        }
        
        Node *get(char ch){
            return links[ch - 'a'];
        }
        
        void setEnd(){
            flag = true;
        }
        
        bool isEnd(){
            if(flag == false){
                return false;
            }
            return true;
        }
    };
    
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *temp = root;
        for(int i=0;i<word.length();i++){
            if(temp -> containsKey(word[i]) == false){
                temp -> put(word[i] , new Node());
            }
            temp = temp -> get(word[i]);
        }
        temp -> setEnd();
    }
    
    bool search(string word) {
        Node *temp = root;
        for(int i=0;i<word.length();i++){
            if(temp -> containsKey(word[i]) == false){
                return false;
            }
            temp = temp -> get(word[i]);
        }
        
        return temp -> isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *temp = root;
        for(int i=0;i<prefix.length();i++){
            if(temp -> containsKey(prefix[i]) == false){
                return false;
            }
            temp = temp -> get(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
