#include <stdio.h>
#define MAXV ((int)2e4)
#define MAXE ((int)2e6)

typedef struct st{
    int node;
    int color;
    struct st *next;
}NODE;

NODE POOL[MAXE*5+10];
NODE HEAD[MAXV+10];
int colors[MAXV+10];

int pcnt;

int K;
int V; int E;

void init(){
    pcnt = 0;
    for (int i =1; i<=MAXV; i++){
        HEAD[i].next = NULL;
        colors[i] = 0;
    }
}

void connect(int a, int b){
    NODE *node = &POOL[pcnt++];
    node->node = b;

    node->next = HEAD[a].next;
    HEAD[a].next = node;
}

int DFS(int vertex, int color){
    colors[vertex] = color;
    
    NODE *node = HEAD[vertex].next;
    for (NODE *p = node; p; p = p->next){
        if (colors[p->node]==color){ // 색칠이 되어 있고 같은 색이다.
            return 0;
        }

        if (!colors[p->node]) {// 색칠이 안되어 있다면
        	if (!DFS(p->node, 3 - color)) {
                return 0;
            }
		}
    }
    return 1; // 성공적으로 연결되어있는 얘들 다 돌았을 때만 1 return
}

int main(){
    scanf("%d", &K);

    for (int tc = 1; tc <= K; tc++){
        int flag = 0;
        init();
        scanf("%d %d", &V, &E);
        for (int j = 0; j < E; j++){
            int a; int b;

            scanf("%d %d", &a, &b);
            connect(a,b);
            connect(b,a);
        }

        for (int v = 1; v <= V; v ++){
            if (!colors[v]){ // 색칠이 안 되어 있어야만 DFS 수행
                flag = DFS(v,1);
                if (!flag) break; // 만약 한 번이라도 flag 가 0 이면 멈추고, NO 출력
            }
            
        }
        
        if (flag) printf("YES\n");
		else printf("NO\n");        
    }

    return 0;
}
