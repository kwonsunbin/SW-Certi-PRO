#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <queue>

using namespace std;

int arr[100000+100];
vector<pair<int,int> > v;

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

template<class T>
void getThird(T &pq){
    while(pq.size()){
        if (v.size()==3){
            cout << v[2].second << endl;
            for (auto i : v){
                pq.push(i);
            }
            v.clear();
            return;
        }
        if (arr[pq.top().second] == pq.top().first){
            if (v[v.size()-1] == pq.top()){
                pq.pop();
                continue;
            }
            v.push_back(pq.top());
            pq.pop();
        }else {
            pq.pop();
        }
    }
    for (auto i : v){
        pq.push(i);
    }
    v.clear();
    cout << "-1" << endl;
    
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
            getThird(min_pq);
        }else{
            getThird(max_pq);
        }
    }
    return 0;
}