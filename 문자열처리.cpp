#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int Q;
int cmd;
vector<string> v;

void toLower(string &str){
    for (auto& c : str ){
        if(c<='Z'){
            c = c+32;
        }
    }
}

void print(){
    for (auto i :v){
        cout << i;
    }
}

void append(string str){
    toLower(str);
    v.push_back(str);
}

bool compare_desc(const string& a, const string& b){
    return a>b;
}

bool compare_len(const string& a, const string& b){
    if (a.size() == b.size()){
        return a<b;
    }else {
        return a.size() < b.size();
    }
}

void sort(int option){
    if(option ==0){
        sort(v.begin(), v.end());
    }else if(option ==1){
        sort(v.begin(), v.end(), compare_desc);
    }else{
        sort(v.begin(), v.end(), compare_len);
    }

    for(auto i=0;i<3; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void expandToFirst(string str){
    v[0] = v[0]+str;
    if(v[0].size()>15){
        v[0] = v[0].substr(0,15);
    }
    cout << v[0] << endl;
}

int main(void){
    cin >> Q;

    for (int i =0; i<Q; i++){
        cin >> cmd ;
        if (cmd == 1){
            string str;
            cin >> str;
            append(str);
        }else if (cmd ==2){
            int option;
            cin >> option;
            sort(option);
        }else{
            string str;
            cin >> str;
            expandToFirst(str);
        }
    }
    return 0;
}