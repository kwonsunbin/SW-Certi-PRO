#include <stdio.h>
#include <set>
#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;
unordered_set<string> s;

int Q;
string str;
int main(void){
    cin >> Q;

    while(Q--){
        cin >> str;
        if(s.count(str)){
            s.erase(str);
        }else {
            s.insert(str);
        }
    }

    cout << s.size();
    return 0;
}