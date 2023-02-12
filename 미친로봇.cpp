#include <stdio.h>
#include <iostream>

using namespace std;
int N;
double odds[4];
double ans;

int map[28][28]; // 시작점 -> 0~13 14 15~28
int visited[28][28]; // 시작점 -> 0~13 14 15~28
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

// N = 2 일 때 ??
void DFS(int x, int y, double odd, int depth){
    visited[x][y] = 1;
    if (depth == N){ // 1 일 때, 4가지, 2일 때, 16가지 
        visited[x][y] = 0;
        return;
    }
    for (int i =0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visited[nx][ny] == 1){
            //cout << nx << "," << ny << endl;
            ans += odd * odds[i];
            //cout << odds[i]/100.0 << endl;
            //cout << ans << endl;
            continue;
        }
        DFS(nx, ny, odd * odds[i], depth+1);
    }
    visited[x][y] = 0;
}

int main(void){
    cin >> N;
    for (int i =0; i<4; i++){
        cin >> odds[i];
    }

    for (int i =0; i<4; i++){
        odds[i] = odds[i]/100.0;
    }


    DFS(14,14, 1.0, 0);
    cout.precision(15);  
    cout << 1.0-ans << endl;


}