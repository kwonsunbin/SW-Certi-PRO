#include <stdio.h>
#include <vector>
using namespace std;

int in;
int out;
int crnt;

int main(void){
    int max = -200000;
    for (int i =0; i<10; i++){
        scanf("%d %d", &out, &in);

        crnt -= out;
        if (crnt > max){
            max = crnt;
        }

        crnt += in;
        if (crnt > max){
            max = crnt;
        }
        
    }

    printf("%d", max);
}