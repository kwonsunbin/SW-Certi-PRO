#include <stdio.h>
#include <iostream>

#define MAXN ((int)1e2)

using namespace std;
int n;

int map[MAXN+10][MAXN+10];

void print(){
    for (int i =1; i<n+1; i++){
        for(int j=1; j<i+1; j++){
            cout << map[i][j] << " " ;
        }
        cout << endl;
    }
}

void init(){
    for (int i =0; i<n+2; i++){
        map[0][i] = -1;
        map[n+1][i] = -1;
        map[i][0] = -1;
        map[i][n+1] = -1; 
    }

    for (int i =1; i<n+1; i++){
        for (int j =i+1; j<n+1; j++){
            map[i][j] = -1;
        }
    }

    for (int i =1; i<n+1; i++){
        for (int j =1; j<=i; j++){
            map[i][j] = 10;
        }
    }
}

int dr[3] = {1,0,-1};
int dc[3] = {1,-1,0};

int dir = 0;

void move(int r, int c, int crnt){
    if (crnt ==10) crnt = 0;
    map[r][c] =crnt++;

    int nr = r + dr[dir];
    int nc = c + dc[dir];

    if (map[nr][nc] != 10){
        dir = (dir+1) %3;
        nr = r + dr[dir];
        nc = c + dc[dir];
        if (map[nr][nc] !=10){
            return;
        }else {
            move(nr,nc,crnt);
        }
    }else {
        move(nr,nc,crnt);
    }

}

int main(void){
    cin >> n;
    init();
    move(1,1,0);
    print();



    

}