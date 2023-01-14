#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TABLE ((int)100007)
#define MAXN ((int)1e6)

typedef struct st{
    char name[6];
    int status;
    struct st *next; 
} NODE;

int N;

NODE POOL[MAXN+10];
NODE HASHTABLE[MAX_TABLE+10]; 
int pcnt;
char stillWorking[MAXN+10][6];
int stillWorkingPtr;

unsigned long hash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

void enter(const char* name){
    NODE *nd = &POOL[pcnt++];
    strcpy(nd->name, name);
    nd->status = 1;

    unsigned long hashKey = hash(name);

    nd->next = HASHTABLE[hashKey].next;
    HASHTABLE[hashKey].next = nd;
}

void leave(const char* name){
    unsigned long hashKey = hash(name);
    for (NODE *p = HASHTABLE[hashKey].next; p; p=p->next ){
        if (strcmp(name, p->name)==0){
            p->status = 0;
            return;
        }
    }
}

int myStrCmp(const char *a, const char *b){
    if (strcmp(a,b)>0){
        return -1;
    }else if (strcmp(a,b)<0){
        return 1;
    }else {
        return 0;
    }
}

int main(){
    scanf("%d", &N);
    for (int i =0; i<N; i++){
        char act[6];
        char name[6];
        scanf(" %s", &name);
        scanf(" %s", &act);

        if (strcmp(act, "enter") ==0){
            enter(name);
        }else {
            leave(name);
        }
    }
    for (int i = 0; i <MAX_TABLE; i++){
        for (NODE *p = HASHTABLE[i].next; p; p=p->next ){
            if (p->status==1){
                strcpy(stillWorking[stillWorkingPtr++], p->name);
            }
        }
    }
    qsort(stillWorking, stillWorkingPtr, sizeof(char)*6, myStrCmp);
    for (int i=0; i<stillWorkingPtr; i++){
        printf("%s\n", stillWorking[i]);
    }

}