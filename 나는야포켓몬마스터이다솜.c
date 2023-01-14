#include <stdio.h>
#include <string.h>
#define MAXN ((int)(1e6))
#define MAXM ((int)(1e6))
#define MAX_TABLE ((int)10007)

typedef struct st {
	char name[21];
    int idx;
	struct st *next;    
}NODE;

int N; int M;
int pcnt;
NODE POOL[MAXN+10];
NODE HASHTABLE[MAX_TABLE+10]; // Name 이 Input으로
char LIST[MAXN+10][21]; // Num 이 Input으로

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

void addToHashTable(int num, const char *name){
    NODE *nd = &POOL[pcnt++];
    strcpy(nd->name, name);
    nd->idx = num;

    unsigned long hashKey = hash(name);
    nd->next = HASHTABLE[hashKey].next;
    HASHTABLE[hashKey].next = nd;
}

void addToList(int num, const char *name){
    strcpy(LIST[num], name);
}

void inputData(){
    scanf("%d %d", &N, &M);

    char pocketmonName[21];

    for (int i = 1; i < N+1; i++){
        scanf("%s", pocketmonName);
        addToHashTable(i, pocketmonName);
        addToList(i,pocketmonName);
    } 
}


int changeStrToInt(const char *str){
	int i, len;
	int sum, mul;

	sum = 0;
	mul = 1;

	for (i = 0; str[i]; i++);
	len = i;

	for (i = len - 1; i >= 0; i--)
	{
		sum += (str[i] - '0') * mul;
		mul *= 10;
	}

	return sum;
}

void search(){
    char question[21];
    for (int i=1 ; i<M+1; i++){
        scanf("%s", question);

        if (question[0]>='A' && question[0]<='Z' ){
            NODE head = HASHTABLE[hash(question)];

            for (NODE *p = head.next; p; p = p->next) {
                if (strcmp(p->name, question) == 0){
                    printf("%d\n", p->idx);
                    break;
                }
            }
        }else {
            printf("%s\n",LIST[changeStrToInt(question)]);
        }
    }
}

int main(){
    inputData();
    search();
}