#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int W; int H;
int map[1000+100][1000+100];

int cnt = 0;
int ans = 0;

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void DFS(int r, int c){
    map[r][c] = 0;
    cnt ++;
    for (int i =0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= H || nc  <0 || nc >= W) continue;
        if ( map[nr][nc] == 1 ) DFS(nr,nc);
    }    
}

int main(void){
    scanf("%d %d", &W, &H);
    char ch;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf(" %c", &ch);      // %c 앞에 공백에 유의
			map[i][j] = ch == '*';  // 목장이 있는 곳에 1을 저장
		}
	}


    for (int r =0; r<H; r++ ){
        for (int c =0; c<W; c++){
            if (map[r][c]==1){
                cnt = 0;
                DFS(r,c);
                if (cnt > ans){
                    ans = cnt;
                }
                
            } 
        }
    } 
    cout << ans;

    return 0;
}