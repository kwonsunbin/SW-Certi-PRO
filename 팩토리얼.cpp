#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int N;
long long ans = 1;
int main(void){
    cin >> N;

    for (int i =N; i>0; i--){
        if (i ==1 ){
            cout << "1! = 1" << endl;
            break;
        }
        cout << i << "! = " << i << " * " << i-1 << "!" << endl;
        ans = ans * i;
    }

    cout << ans;

    return 0;
}