#include <stdio.h>
#include <deque>

#define MAXW ((int)2e2)
#define MAXH ((int)2e2)

using namespace std;

int K;
int W;
int H;
int map[MAXH+10][MAXW+10];
int visited[MAXH+10][MAXW+10];

struct s{
    int r;
    int c;

    s(int R, int C) : r(R), c(C){}
};

deque<s> dq;

int dr[12] = {0,0,1,-1,-2,-1,1,2,2,1,-1,-2};
int dc[12] = {1,-1,0,0,1,2,2,1,-1,-2,-2,-1};

void BFS(){
    dq.push_back(s(0,0));
    while(dq.empty()){
        
    }
}

int main(){
    scanf("%d", &K);
    scanf("%d", &W);
    scanf("%d", &H);

    for (int r = 0; r<H; r++){
        for (int c = 0; c<W; c++){
            scanf("%d", &map[r][c]);
        }
    }



}