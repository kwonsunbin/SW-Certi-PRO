#include <stdio.h>
#define MAXN ((int)1e6)
#define MAXM ((int)1e6)

using namespace std;

int N; int M;
int A[MAXN+10];
int B[MAXM+10];
int aptr;
int bptr;

int main(){
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i=0; i<N; i++){
        scanf("%d",&A[i]); 
    }
    for (int i=0; i<M; i++){
        scanf("%d",&B[i]); 
    }

    while (true){
        if (aptr == N){
            for (int i = bptr; i<M; i++){
                printf("%d ", B[i]);
            }
            break;
        }

        if (bptr == M){
            for (int i = aptr; i<N; i++){
                printf("%d ", A[i]);
            }
            break;
        }
        if(A[aptr]> B[bptr]){
            printf("%d ", B[bptr++]);
        }else {
            printf("%d ", A[aptr++]);
        }
    }



}