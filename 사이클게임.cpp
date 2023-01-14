#include <stdio.h>
#define MAXN ((int)5e5)

using namespace std;

int parent[MAXN+10];
int M; int N;

int Find(int a){
    if (parent[a] == a){
        return a;
    }else {
        return parent[a] = Find(parent[a]);
    }
}

bool Union(int a, int b){
    a = Find(a);
    b = Find(b);
    parent[b] = a;
    if (a == b){
        return true;
    }else {
        return false;
    }
}

int main(void){
    scanf("%d", &N);
    scanf("%d", &M);

    int ans = 0;

    for (int i=0; i<N; i++){
        parent[i]= i;
    }

    for (int i=1; i<M+1; i++){
        int a; int b;
        scanf("%d %d", &a, &b);

        if (Union(a,b)){
            if (ans == 0){
                ans = i;
                break;
            }
        }
        
    }
    
    printf("%d", ans);

}