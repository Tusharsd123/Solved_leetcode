class Solution {
    struct node{
        map<char, node*> m;
        bool isEnd;
        string w;
        node()  {isEnd = false;w = "";}
    };
    
    public:
    
    string search(node * root, string s){
        node * curr = root;
        for(int i= 0;i<s.length();i++){
            if(curr->isEnd) return curr->w;    
            if(!curr->m[s[i]]){
                return s;
            }
            curr = curr->m[s[i]];
        }
        return s;
    }
    
    void insert(node ** t, string s){
        node * curr = (*t);
        for(char c : s){
            if(!curr->m[c]) curr->m[c] = new node();
            curr = curr->m[c];
        }
        curr->isEnd = true;
        curr->w = s;
    }
    
    string replaceWords(vector<string>& d, string s) {
        node * root= new node();
        for(string a : d){
            insert(&root, a);
        }
        string res = "";
        int start = 0;
        s += ' ';
        int l = s.length();
        for(int i = 0;i<l;i++){
            if(s[i] == ' '){
                string w = s.substr(start, i - start);
                w = search(root, w);
                start = i + 1;
                res += w + " ";
            }
        }
        res.pop_back();
        return res;
    }
};