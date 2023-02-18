#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
int const MAXN = 4000;
const int SIZE = 1677716;
const int MOD = 1677715;
vector<pair<int,int> > hashTable[SIZE];  // first value second cnt

int N;
int A[MAXN+10];
int B[MAXN+10];
int C[MAXN+10];
int D[MAXN+10];

int ans;

int hashFunction(int num){
    return num%MOD;
}

void push(int num){
    int hashKey = hashFunction(num);
    for (auto &i : hashTable[hashKey]){
        if (i.first == num) {
            i.second ++;
            return;
        }
    }
    hashTable[hashKey].push_back(make_pair(num,1));
    return;
}

void search(int num){
    int hashKey = hashFunction(num);
    for (auto &i : hashTable[hashKey]){
        if (i.first == num) {
            ans += i.second;
            return;
        }
    }
    return;
}

int main(void){
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for (int i=0; i<N; i++){
        for (int j =0; j<N; j++){
            int crnt = A[i]+B[j];
            push(crnt);
        }
    }

    for (int i=0; i<N; i++){
        for (int j =0; j<N; j++){
            int crnt = -1 * (C[i]+D[j]);
            search(crnt);
        }
    }

    cout << ans ;
    return 0;
    
    
}