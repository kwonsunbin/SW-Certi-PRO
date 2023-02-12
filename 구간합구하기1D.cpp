#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <math.h>
#define MAXN ((int)1e6)
using namespace std;

using LL = long long ;
LL a_accum[MAXN+10];

int N;
int M;
int main(void){
    cin >> N;

    int a;

    for (int i =1; i<N+1;i++){
        cin >> a;
        a_accum[i] = a_accum[i-1]+a;
    }
    cin >> M;
    
    int s = 0;
    int e = 0; 
    while (M--){
        cin >> s >> e;
        cout << a_accum[e] - a_accum[s-1] << endl;
        
    }

    return 0;
}