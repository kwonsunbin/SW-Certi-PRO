#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int N; int M;
int arr[300+10];
int ans = 30001;

bool checkPossible(int n){
    int sum = 0;
    int groupCnt = 0;
    for (int i=0; i<N; i++){
        sum += arr[i];
        if (sum > n){
            groupCnt++;
            sum = arr[i];
        }
    }
    groupCnt++;
    if (groupCnt <= M){
        return true;
    } else {
        return false;
    }
}

void printResult(int ans){
    int sum = 0;
    int cnt = 0;
    int cm = M;
    for (int i=0; i<=N; i++){
        if (sum + arr[i]> ans|| N-i <cm){
            cout << cnt << " ";
            sum = 0;
            cnt = 0;
            cm --;
        }
        sum +=arr[i];
        cnt++;
    }
}

void binarySearch(int s,int e){
    while (s<=e){
        int m = (s+e)/2;
        if (checkPossible(m)){
            ans = m;
            e = m -1;
        }else {
            s = m + 1;
        }
    }
}

int main(void){
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    int myMax = 0;
    for (int i =0; i<N; i++){
        if (arr[i] > myMax) myMax = arr[i];
    }

    int s = myMax;
    int e = 30000;

    binarySearch(s,e);

    cout << ans << endl;
    printResult(ans);

    

    



    return 0;
}