#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

unordered_map<string, int> idmap;
int numOfLogginedInUsers;

int validate(char* ID){
    return idmap.count(ID);
}

int activate(char* ID){
    if (idmap.count(ID)){
        return idmap[ID]==1;
    }
    return 0;
}

int signup(char* ID){
    if (!idmap.count(ID)){
        idmap[ID] = 0;
    }
    return idmap.size(); // idmap size 가 등록된 유저 수가 아니게 되는 케이스가 있다?
}

int close(char* ID){
    if(idmap.count(ID)){
        if (idmap[ID] == 1) numOfLogginedInUsers--;
        idmap.erase(ID);
    }

    return idmap.size();
}

int login(char *ID){
    if(idmap.count(ID) && idmap[ID] == 0){
        idmap[ID] = 1;
        numOfLogginedInUsers++;
    }
    return numOfLogginedInUsers;
}

int logout(char *ID){
    if(idmap.count(ID) && idmap[ID] == 1){
        idmap[ID] = 0;
        numOfLogginedInUsers--;
    }
    return numOfLogginedInUsers;
}




int main(void){
    int Q;
    scanf("%d", &Q);
    int cmd;
    char ID[13];
    
    while(Q--){
        scanf("%d %s", &cmd, ID);
        if(cmd ==1){
            printf("%d\n",validate(ID));
        }else if(cmd == 2){
            printf("%d\n",activate(ID));
        }else if(cmd == 3){
            printf("%d\n",signup(ID));
        }else if (cmd == 4){
            printf("%d\n",close(ID));
        }else if (cmd == 5){
            printf("%d\n",login(ID));
        }else {
            printf("%d\n",logout(ID));
        }
    }
    return 0;
}