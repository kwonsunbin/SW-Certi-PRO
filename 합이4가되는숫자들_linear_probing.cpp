#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

typedef unsigned int UI;
using namespace std;

int const MAXN = 4000;
const int MOD = 30000001;

int N;
int A[MAXN+10];
int B[MAXN+10];
int C[MAXN+10];
int D[MAXN+10];

long long ans;
int cnt[MOD];
int hashTable[MOD];

UI hashFunction(UI num){
    return num%MOD;
}

int probing(int hidx, int key){
    for (int i= hidx; ;i = (i+1)&MOD){
        if (cnt[i]==0 || hashTable[i] == key) return i;
    }
    return -1;
}

int main(void){
    scanf("%d", &N);

    for (int i=0; i<N; i++){
        scanf("%d%d%d%d", A+i, B+i, C+i, D+i);
    }

    for (int i=0; i<N; i++){
        for (int j =0; j<N; j++){
            int crnt = A[i]+B[j];
            int hidx = hashFunction(crnt);
            hidx = probing(hidx, crnt);
            if(cnt[hidx]>0) cnt[hidx] ++;
            else {
                cnt[hidx] =1;
                hashTable[hidx] = crnt;
            }
        }
    }

    for (int i=0; i<N; i++){
        for (int j =0; j<N; j++){
            int crnt = -1 * (C[i]+D[j]);
            int hidx = hashFunction(crnt);
            hidx =probing(hidx,crnt);
            if(hidx>=0) ans += cnt[hidx];
        }
    }

    cout << ans ;
    return 0;
    
    
}