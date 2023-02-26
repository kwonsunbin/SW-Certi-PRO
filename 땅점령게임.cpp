#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int N, Q, crnt;

struct myHash{
    int operator()(const pair<int,int> &place) const {
        return place.first * N + place.second;
    }
};

struct myEqualTo{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const{
        return a.first == b.first && a.second == b.second;
    }
};


unordered_map<pair<int, int>, int, myHash, myEqualTo> m; // ((x좌표,y좌표), 땅 주인)
int x, y;

int numOfLands[4] = {0,0,0,0};

void play(int player, pair<int,int> place){
    // 땅 점령 x
    if (!m.count(place)) {
        m[place]= player;
        numOfLands[player]++;
    }else {
        if (m[place] == player){// 본인 땅
            m.erase(place);
            numOfLands[player]--;
        }else {// 다른 플레이어 땅 : 땅 적은 사람 것이 됨 
            int anotherPlayer = m[place];
            if (numOfLands[player] < numOfLands[anotherPlayer]){
                m[place] = player;
                numOfLands[player]++;
                numOfLands[anotherPlayer]--;
            }
        }
    }
    return;
};

int main(void){

    scanf("%d %d", &N, &Q);

    while(Q--){
        scanf("%d %d", &x, &y);
        play(crnt,make_pair(x,y));
        crnt = (crnt+1) % 4;
    }

    printf("%d\n%d\n%d\n%d", numOfLands[0],numOfLands[1],numOfLands[2],numOfLands[3]);
    return 0;
}