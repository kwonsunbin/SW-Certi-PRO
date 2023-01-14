#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int T;
int a;
int b;
//3 9 7 1 3 9 7 1
// 4 6 4 6 4
void solve(int a, int b){
    int crnt = a%10;
    int target = crnt % 10;
    int cycle = 1;

    if (target == 0){
        printf("10\n");
        return;
    }

    if (b == 1){
        printf("%d\n", target);
        return;
    }

    for (int i = 1; i<b; i++){
        crnt *= a;
        crnt %= 10;

        if (i == b-1){
            printf("%d\n", crnt);
            return;
        }

        if (crnt == target){
            printf("%d\n", int(pow((a%10),((b-1)%cycle+1)))%10);
            return;
        }else {
            cycle++;
        }
            
    }
}

int main()
{
    scanf("%d",&T);
   
    for (int i =0; i<T; i++){
        scanf("%d",&a);
        scanf("%d",&b);
       
        solve(a,b);
       
    }
}
