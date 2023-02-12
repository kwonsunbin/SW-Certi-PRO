#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int a; int b;
int map[100][100];
int ans;
int main(void){
    cin >> n;

    while(n--){
        cin >> a >> b;
        for (int i =0; i<10; i++){
            for (int j=0; j<10; j++){
                map[a+i][b+j] = 1;
            }
        }
        
    } 

    for (int i =0; i<100; i++){
        for (int j=0; j<100; j++){
            if (map[i][j]==1){
                ans ++;
            }
        }
    }

    cout << ans;
    
}