#include <stdio.h>
#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;
unordered_set<int> s;

int Q;
int n;
int main(void){
    cin >> Q;

    while(Q--){
        cin >> n;
        if(s.count(n)){
            s.erase(n);
        }else {
            s.insert(n);
        }
    }

    cout << s.size();
    return 0;
}