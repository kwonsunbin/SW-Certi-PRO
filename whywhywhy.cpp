#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int W; int H;
char map[80+10][+10];

int main(void){
    cin >> W >> H;
    
    for (int r =0; r<H; r++ ){
        string row;
        cin >> row ;
        for (int c=0; c<W; c++){
            map[r][c] = row[c];
        }
    }
    cout << endl;

    

    for (int r =0; r<H; r++ ){
        for (int c=0; c<W; c++){
            cout << map[r][c];
        }
        cout << endl;
    }

    return 0;
}