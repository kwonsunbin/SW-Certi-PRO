#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

struct compare 
{
	bool operator()(const int& parent, const int& child)
	{
		return parent > child; /* parent가 child보다 크면 swap */
	} 
};

priority_queue<int, vector<int>, compare> pq;
int N;

void pq_clear(priority_queue<int, vector<int>, compare>& pq)
{
	priority_queue<int, vector<int>, compare> reset;
	swap(pq, reset);
}

int main(void)
{
    scanf("%d", &N);

    pq_clear(pq);

	for(int i = 0; i < N; i++) {
        int x;

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


	return 0;
}