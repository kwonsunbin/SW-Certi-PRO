#include <stdio.h>

using namespace std;

int E; int S; int M;
int e=1; int s=1; int m=1;
int ans = 1;

int main(){
    scanf("%d %d %d", &E, &S, &M);

    while(true){
         
        if (e== E && s==S && m==M){
            break;
        }
        e++; s++; m++; ans++;

        if (e==16){
            e = 1;
        }
        if (s==29){
            s = 1;
        }
        if (m==20){
            m = 1;
        }
    }

    printf("%d", ans);
}