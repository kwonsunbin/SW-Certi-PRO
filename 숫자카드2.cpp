#include <stdio.h>
#include <vector>
#include <map>

using namespace std;



int arrM[500000+100];
int ans[500000+100];

int main(void){
    map<int,int> m;
    int N;
    scanf("%d", &N);

    for (int i =0; i<N; i++){
        int a;
        scanf("%d", &a);
        m[a] ++;
    }
    int M;
    scanf("%d", &M);
    for (int i =0; i<M; i++){
        int b;
        scanf("%d", &b);
        printf("%d ",m[b]);
    }

}