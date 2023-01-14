#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T;
int N;
vector<string> v;

char map[12][9];
char temp[3];

void init(){
    map = {{'-','-','-','o','o','o','-','-','-'},
     {'-','-','-','o','o','o','-','-','-'},
     {'-','-','-','o','o','o','-','-','-'},
     {'g','g','g','w','w','w','b','b','b'},
     {'g','g','g','w','w','w','b','b','b'},
     {'g','g','g','w','w','w','b','b','b'},
     {'-','-','-','r','r','r','-','-','-'},
     {'-','-','-','r','r','r','-','-','-'},
     {'-','-','-','r','r','r','-','-','-'},
     {'-','-','-','y','y','y','-','-','-'},
     {'-','-','-','y','y','y','-','-','-'},
     {'-','-','-','y','y','y','-','-','-'}};
}

void rotate(string cmd){
    if (strcmp(cmd, "U+")==0){
        map[2][3] = map[3][6];
        map[2][4] = map[4][6];
        map[2][5] = map[5][6];

        map[3][2] = map[2][5]; 
        map[4][2] = map[2][4];
        map[5][2] = map[2][3];

        map[2]
    }else if (strcmp(cmd, "U-")==0){
        
    }
}

void print(){
    for (int i =0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%c",map[3+i][3+j]);
        }
        printf("\n");
    }
}

int main(void){
    scanf("%d", &T);

    for (int i=0; i<T; i++){
        v.clear();
        init();
        scanf("%d", &N);
        

        for (int j=0; j<N; j++){
            scanf("%s", temp);
            v.push_back(temp);
        }

        for (int k=0; k<v.size(); k++){
            rotate(v[k]);
        }

        print();
        
    }

}