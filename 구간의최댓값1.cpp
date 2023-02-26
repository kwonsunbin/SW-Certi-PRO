#include <stdio.h>
#include <set>
#include <unordered_set>
#include <iostream>
#include <string>
#include <algorithm>
#define MAXN ((int)2e5)

using namespace std;
int N, Q;
int A[MAXN+10];
int tree[MAXN+10];

void build(int now, int s, int e){
    if (s==e){
        tree[now]= A[s];
        return;
    }

    int lch = 2*now;
    int rch = 2*now +1;
    int m = (s+e) /2;
    build(lch,s,m);
    build(rch,m+1,e);
    tree[now] = max(tree[lch], tree[rch]);
}

void buildTree(){
    build(1,1,N);
}

int query(int now, int s, int e, int fs, int fe){
    if(e<fs || fe <s) return 0;
    if (fs <= s && e <= fe) return tree[now];

    int lch = now*2;
    int rch = now*2+1;
    int m =(s+e)/2;
    int left = query(lch,s,m,fs,fe);
    int right = query(rch,m+1,e,fs,fe);
    return max(left,right);
}

int main(void){
    cin >> N >> Q;

    for (int i =0; i<N;i++){
        cin >> A[i]; 
    }

    buildTree();

    int fs, fe;
    for (int i=0; i<Q; i++){
        cin >> fs >> fe;
        cout << query(1,1,N,fs,fe) << endl;
    }


    return 0;
}