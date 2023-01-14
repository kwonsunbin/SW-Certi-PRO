#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;

map<string,int> dict;


bool compare(const pair<string,int>& a, const pair<string,int>& b){
    if (a.second > b.second){
        return true;
    }else if (a.second ==b.second){
        if (a.first > b.first){
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}

int main(void){
    scanf("%d", &N);
    string temp;
    for (int i=0; i<N; i++){
        cin >> temp;

        dict[temp]++;
    }

    vector<pair<string,int> > v;
    for (auto& it : dict) {
        v.push_back(it);
    }
    

    sort(v.begin(), v.end(), compare);

    printf("%s %d", v[0].first.c_str(), v[0].second);
    return 0;
}
