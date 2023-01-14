#include <stdio.h>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
int N; int M;

struct Node{
    bool isWord;
    unordered_map<char,Node*> children;

    Node()
    {
        isWord = false;
    }
};

Node *root = new Node();
int ans;

void insert(string word){
    Node *temp = root;
    for(char c:word){
        if (temp->children.count(c) == 0){
            Node* newNode= new Node();
            temp->children[c]= newNode;
            temp = temp->children[c];
        }else {
            temp = temp->children[c];
        }
    }
    temp->isWord=true;
}

bool search(string word){
    Node *temp = root;
    for (char c:word){
        if (temp->children.count(c)==0){
            return false;
        }else {
            temp = temp->children[c];
        }
    }
    return temp->isWord;
}

int main(void){
    scanf("%d %d", &N, &M);
    
    for (int i=0; i<N; i++){
        string a;
        cin >> a;
        insert(a);
    }
    for (int i=0; i<M; i++){
        string a;
        cin >> a;
        if (search(a)){
            ans++;
        }
    }

    printf("%d", ans);
    return 0;
}