#include<bits/stdc++.h>
using namespace std;
class trienode{
    public:
        char data;
        trienode* children[26];
        bool isterminal;
        trienode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isterminal=false;
        }
};

class trie{
    public:
        trienode* root;
        trie(){
            root=new trienode('\0');//put null at root
        }
        void insertutil(trienode* root,string word){
            //base case
            if(word.length()==0){
                root->isterminal=true;//we reached last node
                return;
            }
            //assume word is in caps
            int index=word[0]-'A';
            trienode* child;

            //present
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{
                //absent
                child=new trienode(word[0]);
                root->children[index]=child;
            }

            insertutil(child,word.substr(1));
        }
        void insertword(string word){
            insertutil(root,word);
        }

        //searching
        bool searchutil(trienode* root,string word){
            //base case
            if(word.length()==0){
                return root->isterminal;//return true if we only want to check the prefix of some word like if using that prefix some word exist or not
            }
            int index=word[0]-'A';
            trienode* child;
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{
                //absent
                return false;
            }
            return searchutil(child,word.substr(1));
        }
        bool searchword(string word){
            return searchutil(root,word);
        }
         bool isEmpty(trienode* root)
    {
        for(int i=0;i<26;i++)
            if(root->children[i])
                return false;
        
        return true;
    }

   trienode* deleteutil(trienode* root, const string& word) {
    if (root == nullptr) // Null pointer check
        return nullptr;

    // Last character being processed
    if (word.length() == 0) {
        // This will not be a word after removal
        if (root->isterminal)
            root->isterminal = false;

        // If this is not a prefix of any other word (no children)
        if (isEmpty(root)) {
            delete root; // Deallocate memory
            return nullptr; // Return null pointer
        }
        return root;
    }

    // Recursion call
    int index = word[0] - 'A';
    if (root->children[index] != nullptr) {
        root->children[index] = deleteutil(root->children[index], word.substr(1));
    }

    // Backtracking
    // If root has no child (as its only child got deleted) and it is also not the end of any other word
    if (isEmpty(root) && !root->isterminal) {
        delete root; // Deallocate memory
        return nullptr; // Return null pointer
    }
    return root;
}

    
    trienode* deleteword(string word)
    {
         return deleteutil(root,word);
    }
};


int main(){
    trie* t=new trie();
    t->insertword("ABCD");
    t->insertword("TIME");
    cout<<"present or not "<<t->searchword("ABCD")<<endl;

    t->deleteword("ABCD");
    cout<<"present or not "<<t->searchword("ABCD");
}

//TC:insertion and deletion and searching->O(L);
//solve ques 80 of leetcode