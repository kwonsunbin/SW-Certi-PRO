#include <stdio.h>
#include <string.h>
#define MAXN ((int)5e5)
#define MAX_TABLE ((int)10007)

typedef struct st {
	char name[21];
	struct st *next;    
}NODE;

int N; int M;
int pcnt;
int answer;
NODE POOL[MAXN+10];
NODE HASHTABLE[MAX_TABLE+10]; 

char sortedNameArr[MAXN+10][21];
int sortedNameArrLength;

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

void addNameToSortedNameArr(const char *name){
    if (sortedNameArrLength == 0){
        strcpy(sortedNameArr[0], name);
        sortedNameArrLength++;
        return;
    }

    for (int i = 0; i < sortedNameArrLength+1; i++){
        if (i ==sortedNameArrLength){
            strcpy(sortedNameArr[i],name);
            sortedNameArrLength++;
            return;
        }
        if (strcmp(name, sortedNameArr[i]) < 0 ){
            for (int j = sortedNameArrLength; j > i; j--){
                strcpy(sortedNameArr[j],sortedNameArr[j-1]);
            }
            strcpy(sortedNameArr[i], name);
            sortedNameArrLength++;
            return;
        }else {
            continue;
        }
    }
}

void addNameToHashTable(const char *name){
    NODE *nd = &POOL[pcnt++];
    strcpy(nd->name, name);

    unsigned long hashKey = hash(name);
    nd->next = HASHTABLE[hashKey].next;
    HASHTABLE[hashKey].next = nd;
}

int checkIfSameNameExists(const char *name){
    for (NODE *p = HASHTABLE[hash(name)].next; p; p = p->next) {
        if (strcmp(p->name, name) == 0){
            answer++;
            addNameToSortedNameArr(name);
            break;
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);

    char crntName[21];

    for ( int i = 0; i < N; i++){
        scanf("%s", &crntName);
        addNameToHashTable(crntName);
    }

    for ( int i = 0; i < M; i++){
        scanf("%s", &crntName);
        checkIfSameNameExists(crntName);
    }
    printf("%d\n", answer);
    for ( int i = 0; i < sortedNameArrLength; i++){
        printf("%s\n", sortedNameArr[i]);
    }
}