#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int N; int M;
int sum = 0;
int cnt = 0;

bool checkSosu(int a){
    if ( a == 1){
        return false;
    }
    for (int i=2; i<a; i++){
        if (a%i==0) return false;
    }
    return true;
}

int main(void){
    cin >> N;
    cin >> M;
    int myMin = 0;
    for (int i=N; i<M+1; i++){
        if (checkSosu(i) ) {
            cnt ++;
            sum+=i;
            if (cnt == 1){
                myMin = i;
            }
        } 
    }
    if (!cnt) cout << -1 ; 
    else {cout << sum << endl; cout << myMin ;}



    return 0;
}