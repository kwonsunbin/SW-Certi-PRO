#include <stdio.h>
#define MAXN ((int)1e2)

int N; 
int M;
int ANSWER;
typedef struct st{
	int val;
	struct st *next;
}NODE;

int VISIT[MAXN + 10];
NODE HEAD[MAXN + 10];
//NODE TAIL[110]; 
NODE POOL[MAXN*MAXN];
int pcnt;

int QUE[MAXN+10];
int wp; int rp;

void push(int n){ 
    if (VISIT[n] ==1 ){
        return;
    }
    VISIT[n] = 1;
    QUE[wp++] = n;
}
int pop(){return QUE[rp++];}
int empty() {return wp ==rp;}

void init() 
{
	pcnt = 0;
    wp = rp = 0;
	for (int i = 1; i <= N;i++) HEAD[i].next = 0;
    //for (int i = 1; i <= N;i++) TAIL[i].next = 0; 
	for (int i = 1; i <= N;i++) VISIT[i] = 0;
	
	ANSWER = 0;
}

void addConnection(int a, int b)
{
	NODE *nd = &POOL[pcnt++]; /* POOL에서 메모리를 가져온다 */ 
	nd->val = b; /* node에 값을 설정. */

    nd->next = HEAD[a].next;
	HEAD[a].next = nd;

    /*
    if (HEAD[p].next == NULL && TAIL[p].next == NULL)
		HEAD[p].next = TAIL[p].next = nd;
	else
	{
		TAIL[p].next->next = nd;
		TAIL[p].next = nd;
	}
    */
}

void inputData(){
  int N; int M;
  int a; int b;
  scanf("%d", &N);
  scanf("%d", &M);

  for (int i = 0; i < M ; i++){
    scanf("%d %d", &a, &b);
    addConnection(a, b);
    addConnection(b, a);
  }
  
}

void printConnections(){
    for (int i = 1; i<=10; i++){
        printf("node %d connected to : ", i);

        NODE *crnt = HEAD[i].next;
        while (crnt) {
            printf("%d ", crnt->val );
            crnt = crnt->next;
        } 
        //for (NODE *p = HEAD[head].next; p; p = p->next) printf("%d ", p->node);
        printf("\n");
    }
}

void BFS(){
    push(1);
    VISIT[1] = 1;
    ANSWER --;

    int crnt;

    while(!empty()){
        crnt = pop();
        ANSWER++;
        for (NODE *p = HEAD[crnt].next; p; p = p->next) {
            push(p->val);
        }
    }
    
}

int main() {
    //init();
    inputData();
    //printConnections();
    BFS();

    printf("%d", ANSWER);
    return 0;
}