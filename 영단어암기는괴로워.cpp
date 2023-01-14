#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN ((int) 1e5)
#define MAX_HASH ((int)10007)

using namespace std;

struct node{
    int cnt;
    int len;
    string word;

    node(int cnt, int len, string word){
        this -> cnt = cnt;
        this -> len = len;
        this -> word = word;
    }
};

vector<node> hashMap[MAX_HASH];

int getHash(const char *str)
{
	int hash = 5381;
	int c;

	while ((c = *str++))
	{
		hash = (((hash << 5) + hash) + c) % MAX_HASH;
	}

	return hash % MAX_HASH;
}

bool compare(const node a, const node b){
    if (a.cnt > b.cnt) {
        return true;
    }else if (a.cnt == b.cnt && a.len > b.len){
        return true;
    }else if (a.cnt == b.cnt && a.len == b.len && a.word < b.word){
        return true;
    }else {
        return false;
    }
}
vector<node> v;
int N;
int M;

int main(void){
    scanf("%d", &N);
    scanf("%d", &M);
    string temp_str;
    int flag = 0;

    for (int i = 0; i<N; i++){
        cin >> temp_str;
        if (temp_str.length() >= M){
            for( int i =0; i< hashMap[getHash(temp_str.c_str())].size(); i++){
                if (hashMap[getHash(temp_str.c_str())][i].word.compare(temp_str)==0){
                    hashMap[getHash(temp_str.c_str())][i].cnt++;
                    flag = 1;
                    break;
                }
            }            
            if (!flag){
                hashMap[getHash(temp_str.c_str())].push_back(node(1,temp_str.length(),temp_str));
            }
            flag = 0;
        }
    }

    for (int i =0; i<MAX_HASH; i++){
        for (int j=0; j<hashMap[i].size(); j++){
            v.push_back(hashMap[i][j]);
        }
    }

    sort(v.begin(), v.end(), compare);


    for (int i = 0; i<v.size(); i++){
        cout << v[i].word << endl;
    }


}
