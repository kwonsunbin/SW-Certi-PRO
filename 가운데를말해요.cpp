#include <stdio.h>
#include <queue>
#define MAXN ((int) 1e6)

using namespace std;

int K;
int N;

struct compare{
    bool operator()(const int a, const int b){
        return a>b;
    }
};

priority_queue<int> maxPq;
priority_queue<int, vector<int>, compare> minPq;

void pqClear(){
    priority_queue<int> resetMaxPq;
    priority_queue<int, vector<int>, compare> resetMinPq;

    swap(maxPq, resetMaxPq);
    swap(minPq, resetMinPq);
}

int main(void){
    scanf("%d", &N);
    scanf("%d", &K);

    minPq.push(K);
    printf("%d\n",minPq.top());

    for (int i =1; i<N; i++){
        scanf("%d",&K);
        if (minPq.size()==maxPq.size()){ // 같음
            if (maxPq.top() < K){
                minPq.push(K);
            }else {
                minPq.push(maxPq.top());
                maxPq.pop();
                maxPq.push(K);
            }
            printf("%d\n",minPq.top());
        }else { // minPq 가 1개 더 많음!?
            if(minPq.top()<K){
                maxPq.push(minPq.top());
                minPq.pop();
                minPq.push(K);
            }else {
                maxPq.push(K);
            }
            printf("%d\n",maxPq.top());
        }        
    }


    return 0;

}
