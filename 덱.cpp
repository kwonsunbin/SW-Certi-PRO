#include <stdio.h>
#include <deque>
#include <string.h>

using namespace std;

int N;
int X;
char cmd[20];
deque<int> dq;

int main(){
    scanf("%d", &N);

    for (int i = 0; i<N; i++){
        scanf("%s", cmd);
        if (strcmp(cmd, "push_front")==0){
            scanf("%d", &X);
            dq.push_front(X);
        }
        else if(strcmp(cmd, "push_back")==0){
            scanf("%d", &X);

            dq.push_back(X);
        }else if(strcmp(cmd, "pop_front")==0){
            if (dq.empty()==1){
                printf("-1\n");
                continue;
            }
            printf("%d\n", dq.front());        
            dq.pop_front();
        }else if(strcmp(cmd, "pop_back")==0){
            if (dq.empty()==1){
                printf("-1\n");
                continue;
            }
            printf("%d\n", dq.back()); 
            dq.pop_back();
        }else if(strcmp(cmd, "size")==0){
            printf("%d\n", dq.size());
        }else if(strcmp(cmd, "empty")==0){
            printf("%d\n",dq.empty());
        }else if(strcmp(cmd, "front")==0){
            if (dq.empty()==1){
                printf("-1\n");
                continue;
            }
            
            printf("%d\n", dq.front());
        }else {
            if (dq.empty()==1){
                printf("-1\n");
                continue;
            }
            
            printf("%d\n", dq.back());
        }
    }

    
}
