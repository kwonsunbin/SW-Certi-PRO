#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
int const LM = 4001;
const int MOD = 1<<24;

int N;
int A[LM];
int B[LM];
int C[LM];
int D[LM];

int ans;

int bcnt;
struct Node{
    int key; int cnt;
    Node * next;
    Node * alloc(int nkey, Node *np){
        key = nkey, cnt = 1, next =np;
        return this;
    }
};
Node buf[LM*LM];
Node *htab[MOD];

int hashF(int key){
    return key %MOD;
}
Node * probing(int hidx, int key){
    Node *p = htab[hidx];
    for (Node *p; p; p->next){
        if(p->key ==key) return p;
    }
}

int main(void){
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for (int i=0; i<N; i++){
        for (int j =0; j<N; j++){
            int key = A[i]+B[j];
            int hidx = hashF(key);
            Node *p = probing(hidx,key);
            if(p) p->cnt++;
            else {
                htab[hidx] = buf[bcnt++].alloc(key, htab[hidx]);
            }
        }
    }

    for (int i=0; i<N; i++){
        for (int j =0; j<N; j++){
            int key = -1 * (C[i]+D[j]);
            int hidx = hashF(key);
            Node *p = probing(hidx,key);
            if (p) ans+= p->cnt;
        }
    }

    cout << ans ;
    return 0;
    
    
}