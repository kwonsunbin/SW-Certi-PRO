#include <stdio.h>
#include <vector>
#define MAXN ((int)12);

using namespace std;

int N;
int a;
int mymax = - 2000000000;
int mymin =   2000000000;

vector<int> oper;
vector<int> nums;

// 중복 순열 구현하기 ?!

// 3
// 3 4 5
// 1 0 1 0
void DFS(int result, int depth){
    if (depth == N-1){
        if (result > mymax){
            mymax = result;
        }
        if (result < mymin){
            mymin = result;
        }
        return;
    }
    for (int i =0; i<4; i++){
        if (oper[i] == 0){
            continue;
        }
        else {
            depth++;
            oper[i]--;
            int newResult;
            if (i ==0){
                newResult = result + nums[depth];
            } else if(i==1){
                newResult = result - nums[depth];
            } else if (i==2){
                newResult = result * nums[depth];
            }else {
                newResult = result / nums[depth];
            }
            DFS(newResult, depth);
            depth--;
            oper[i]++;
        }
    }
    return ;
}

int main(void){
    scanf("%d", &N);

    for (int i =0; i<N; i++){
        scanf("%d", &a);
        nums.push_back(a);
    }

    for (int i=0; i<4; i++){
        scanf("%d", &a);
        oper.push_back(a);
    }

    DFS(nums[0],0);

    printf("%d\n", mymax);
    printf("%d\n", mymin);

}