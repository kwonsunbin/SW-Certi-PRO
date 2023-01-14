#include <stdio.h>
#define MAXN ((int)5e2)
#define MAXM ((int)5e2)
int N; int M;
int map[MAXN+10][MAXM+10];

int crntPaintArea = 0;
int maxPaintArea = -1;
int cntPaint = 0;

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void DFS(int r, int c){
    map[r][c] = -1;
    crntPaintArea ++;

    for (int i = 0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr <0 | nc<0 | nr>=N | nc>=M){
            continue;
        }else {
            if (map[nr][nc]== 1){
                DFS(nr,nc);
            }
        }
        
    }
}

int main(){
    scanf("%d", &N);
    scanf("%d", &M);

    for (int r =0; r<N ; r++){
        for (int c=0; c<M; c++){
            scanf("%d", &map[r][c]);
        }
    }

    for (int r =0; r<N ; r++){
        for (int c=0; c<M; c++){
            if(map[r][c] == 1){
                DFS(r,c);
                cntPaint++;
                if (crntPaintArea > maxPaintArea){
                    maxPaintArea = crntPaintArea;
                }
                crntPaintArea = 0;
            }
        }
    }

    printf("%d\n", cntPaint);
    if (maxPaintArea == -1){
        printf("0\n");
    }else {
        printf("%d\n", maxPaintArea);
    }
}