#include <stdio.h>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;


struct compare{
    bool operator()(const int& parent, const int& child){
        if (abs(parent) > abs(child)){
            return true;
        }else if (abs(parent)== abs(child)){
            return parent > child;
        }else {
            return false;
        }
    }
};

priority_queue<int, vector<int>, compare> pq;
int N;
int x;


void pq_clear(priority_queue<int, vector<int>, compare>& pq)
{
	priority_queue<int, vector<int>, compare> reset;
	swap(pq, reset);
}

int main(){
    scanf("%d", &N);
    
    for (int i = 0; i<N; i++){
        scanf("%d", &x);

        if (x == 0){
            if (pq.empty()){
                printf("0\n");
                continue;
            }
            printf("%d\n", pq.top());
            pq.pop();
        }else {
            pq.push(x);
        }
    }
}