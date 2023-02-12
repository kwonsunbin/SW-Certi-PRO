#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> yaksoos;
int main(void){
    cin >> N;

    for (int i =1; i<N+1; i++){
        if (N%i ==0){
            yaksoos.push_back(i);
        }
    }
}