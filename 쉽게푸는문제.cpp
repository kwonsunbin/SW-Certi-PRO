#include <stdio.h>
#include <vector>
using namespace std;

int A; int B;
vector<int> v;

int main(void){
    scanf("%d %d", &A, &B);
    int crnt = 1;
    int ans = 0;

    for (;;){
        for (int i=1; i<=crnt; i++ ){
            v.push_back(crnt);
        }

        if (v.size() > 1000){
            break;
        }
        
        crnt ++;
    }

    // A가 3, B가 7 이면, 2 부터 ~ 6까지
    for (int i = A-1; i<B; i++){
        ans += v[i];
    }

    printf("%d", ans);

}