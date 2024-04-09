#include<bits/stdc++.h>
using namespace std;

class trienode{
    public:
    bool isEnd=0;
    trienode* children[26];
     trienode() {
        for (auto &a : children) a = NULL;
    }
};
    void insert(string word,trienode* root) {
        trienode* node=root;
        for(char &i:word){
            if(!node->children[i-'a']){
                node->children[i-'a']=new trienode();
            }
            node=node->children[i-'a'];
        }
        node->isEnd=1;
    }
    
    bool search(string word,trienode* root) {
        trienode* node=root;
        for(char &c:word){
            if(!node->children[c-'a']){
                return 0;
            }
            node=node->children[c-'a'];
        }
        if(node->isEnd)return 1;
        return 0;
    }
    
    bool startsWith(string prefix,trienode* root) {
        trienode* node=root;
        for(char &c:prefix){
            if(!node->children[c-'a']){
                return 0;
            }
            node=node->children[c-'a'];
        }
        return 1;
    }
int main(){
        //"insert","search","search","startsWith","insert","search"
        vector<string> words={"apple","apple","app","app","app","app"};
        trienode* root=new trienode();
        string opn="insert";
        insert("apple",root);
        cout<<"Inserted"<<"\n";
        if(search("apple",root))cout<<"TRUE"<<"\n";
        else cout<<"FALSE\n";
        if(startsWith("app",root))cout<<"TRUE"<<"\n";
        else cout<<"FALSE\n";
        if(search("app",root))cout<<"TRUE"<<"\n";
        else cout<<"FALSE\n";
    return 0;
}
