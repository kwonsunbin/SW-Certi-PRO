#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int T;
int Q;
string cmd;
set<int> s;
int x;
int y;

void insert(){
    int x;
    cin >> x;
    s.insert(x);
}

void erase(){
    int x;
    cin >> x;
    s.erase(x);
}

void update(){
    int x; int y;
    cin >> x >> y;

    auto yexist = s.find(y);
    auto xexist = s.find(x);

    if(xexist != s.end() && yexist == s.end()){
        s.erase(x);
        s.insert(y);
    }
}

void front(){
    int c;
    int cnt = 1;
    cin >> c;

    if (s.empty()){
        cout << "empty" << endl;
        return;
    }

    if (s.size()<c){
        cout << *(--s.end()) << endl;
    }else {
        for (auto it= s.begin(); it != s.end(); it++){
            if(cnt==c){
                cout << *it << endl;
                return;
            }
            cnt++;
        }
    }
}


void back(){
    int c;
    int cnt = 1;
    cin >> c;

    if (s.empty()){
        cout << "empty" << endl;
        return;
    }

    if (s.size()<c){
        cout << *(s.begin()) << endl;
    }else {
        for (auto it = s.rbegin(); it != s.rend(); it++){
            if(cnt==c){
                cout << *it << endl;
                return;
            }
            cnt++;
        }
    }
}

int main(void){
    cin >> T;

    while (T--){
        cin >> Q;
        s.clear();
        while (Q--){
            cin >> cmd;
            if(cmd[0] == 'i'){
                insert();
            }else if (cmd[0] == 'e'){
                erase();
            }else if (cmd[0] == 'u'){
                update();
            }else if (cmd[0] == 'f'){
                front();
            }else {
                back();
            }
        }
    }
}