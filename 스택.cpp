#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

stack<int> myStack;
int N;
char cmd;
int a;

void insert(int a){
    myStack.push(a);
}

void count(){
    cout << myStack.size() << endl;
}

void pop(){
    if ( myStack.empty()) cout << "empty" << endl;
    else {
        cout << myStack.top() << endl;
        myStack.pop();
    }
}
int main(void){
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> cmd;
        if(cmd == 'i'){
            cin >> a;
            insert(a);
        }
        else if(cmd == 'c') count();
        else pop();
    }

    return 0;
}