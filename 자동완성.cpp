#include <stdio.h>

struct TRIE
{
    bool Finish;
    TRIE *Node[26];
    TRIE(){ 
        Finish = false;  
        for (int i = 0; i < 26; i++) Node[i] = NULL;
    }

    void Insert(char *crnt){
        if (*crnt == NULL){
            Finish = true;
            return;
        }
        
        int idx = *crnt - 'A';
        if (Node[idx] == NULL) Node[idx] = new TRIE();

        Node[idx]->Insert(crnt + 1);
    }

    bool Find(char *crnt){
        if (*crnt == NULL){
            if (Finish == true) return true;
            return false;
        }
        int idx = *crnt - 'A';
        if (Node[idx] == NULL) return false;
        return Node[idx]->Find(crnt + 1);
    }


};



int main(void){
    TRIE* root = new TRIE();

}