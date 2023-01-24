#include <stdio.h>
#include <vector>

using namespace std;

int N; int S;
int ans;

vector<int> v;
// 1, 2, 3
// 4
void DFS(int result, int s){
    if (s > 0 && result == S){
        ans ++;
    }
    if (s >= N){
        return;
    }
    for (int i = s; i<N; i++){
        DFS(result+ v[i], i+1); // 3, 1 -> -2 2 -> 0, 3
    }
}


int main(void){
    scanf("%d %d", &N, &S);

    for (int i =0; i<N; i++){
        int n;
        scanf("%d", &n);
        v.push_back(n);
    }

    DFS(0, 0);
    
    printf("%d", ans);
    return 0;
}