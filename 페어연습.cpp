#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    vector<pair<int,string> > v;
    v.push_back(pair<int,string>(90,"윤애숙"));
    v.push_back(pair<int,string>(100,"김유정"));
    v.push_back(pair<int,string>(80,"권순빈"));

    for(auto student : v){
        printf("%s : ", student.second.c_str());
        printf("%d\n", student.first);
    }
    sort(begin(v), end(v));

    for(auto student : v){
        printf("%s : ", student.second.c_str());
        printf("%d\n", student.first);
    }

    
    
}