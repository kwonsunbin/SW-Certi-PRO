#include <stdio.h>

using namespace std;

int board_matrix[6][6]; 

int main(void){
    for (int i =0; i<6; i++){
        for (int j=0; j<6; j++){
            scanf("%d", &board_matrix[i][j]);
        }
    }

}