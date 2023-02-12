#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <queue>

using namespace std;

int arr[100000+100];

priority_queue<pair<int,int> > max_pq; // value, id
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > min_pq; // value, id

int Q;
int cmd;
int id;
int value;

void push(){
    arr[id] = value;
    max_pq.push(make_pair(value,id));
    min_pq.push(make_pair(value,id));
}

void remove(){
    arr[id] = 0;
}

void printIdOfBiggestValue(){
    if (max_pq.empty()){
        cout << -1 << endl;
        return;
    }
    if (arr[max_pq.top().second] == max_pq.top().first){
        cout << max_pq.top().second << endl;
    }else {
        max_pq.pop();
        printIdOfBiggestValue();
    }
}

void printIdOfSmallestValue(){
    if (min_pq.empty()){
        cout << -1 << endl;
        return;
    }
    if (arr[min_pq.top().second] == min_pq.top().first){
        cout << min_pq.top().second << endl;
    }else {
        min_pq.pop();
        printIdOfSmallestValue();
    }
}

int main(void){
    cin >> Q;

    while(Q--){
        cin >> cmd;
        if(cmd==1){
            cin >> id >> value;
            push();
        }else if(cmd==2){
            cin >> id;
            remove();
        }else if(cmd==3){
            printIdOfSmallestValue();
        }else{
            printIdOfBiggestValue();
        }
    }
    return 0;
}