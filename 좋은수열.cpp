#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
int flag;
vector<int> v;

bool checkGood(){
    int maxCompareLen = (v.size())/2; 
    if (maxCompareLen == 0){
        return true;
    }

    for ( int i =1; i<maxCompareLen+1; i++){ // 1211 -> i=1,2  동작
        int test = 0;
        for (int j =0; j<i; j++){ // i=1 일 떄 ~ j=0 만 동작, i = 2일 때, j=0,1 동작
            if (v[v.size()-1-j] == v[v.size()-1-i-j]){
                test++;
            }
        }
        if (test == i){
            return false;
        }
    }

    return true;
}

void DFS(){ 
/*
    printf("debug : ");
    for (int i =0; i<v.size(); i++){
            printf("%d", v[i]);
    }
    printf("\n");
*/
    if (!checkGood() | flag){
        return;
    }
    if (v.size() == N){
        for (int i =0; i<v.size(); i++){
            printf("%d", v[i]);
        }
        printf("\n");
        flag = 1;
        return;
    }
    v.push_back(1);
    DFS();
    v.pop_back();

    v.push_back(2); 
    DFS();
    v.pop_back();

    v.push_back(3);
    DFS();
    v.pop_back();
}

int main(void){
    scanf("%d", &N);
    DFS();
}