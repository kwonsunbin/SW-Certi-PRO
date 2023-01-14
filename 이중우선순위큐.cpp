#include <stdio.h>
#define MAXN ((int)1e6)
using namespace std;

struct node{
    int id;
    int value;
};

node maxPq[MAXN+10];
node minPq[MAXN+10];
int maxPqPtr;
int minPqPtr;

int T;
char opeartion;
int N;

void maxPqPush(int value, int id){
    maxPq[++maxPqPtr].value = value;
    maxPq[maxPqPtr].id = id;

    for (int i=maxPqPtr; i>1; i/=2){
        if (maxPq[i/2].value < value ){
            int temp = maxPq[i/2].value;
            maxPq[i/2].value = value;
            maxPq[i].value = temp;
        }else {
            break;
        }
    }
}

void minPqPush(int value, int id){
    minPq[++minPqPtr].value = value;
    minPq[minPqPtr].id = id;
    for (int i=minPqPtr; i>1; i/=2){
        if (minPq[i/2].value > value ){
            int temp = minPq[i/2].value;
            minPq[i/2].value = value;
            minPq[i].value = temp;
        }else {
            break;
        }
    }
}

int maxPqPop(){
    int ret = maxPq[1].value;
    maxPq[1] = maxPq[maxPqPtr];
    maxPq[maxPqPtr--].value=-((int)2e9);
    for (int i=1; i*2<maxPqPtr; ){
        if (maxPq[i].value< maxPq[2*i].value && maxPq[i].value<maxPq[2*i+1].value){
            break;
        }else if(maxPq[2*i].value<maxPq[2*i+1].value){
            int temp = maxPq[2*i+1].value;
            maxPq[2*i+1].value= maxPq[i].value;
            maxPq[i].value = temp;
            
            i = 2*i+1;
        }else {
            int temp = maxPq[2*i].value;
            maxPq[2*i].value= maxPq[i].value;
            maxPq[i].value = temp;
            i = 2*i;
        }
    }

    return ret;
}

int minPqPop(){
    int ret = minPq[1].value;
    minPq[1] = minPq[minPqPtr];
    minPq[minPqPtr--].value=-((int)2e9);
    for (int i=1; i*2<minPqPtr; ){
        if (minPq[i].value> minPq[2*i].value && minPq[i].value>minPq[2*i+1].value){
            break;
        }else if(minPq[2*i].value>minPq[2*i+1].value){
            int temp = minPq[2*i+1].value;
            minPq[2*i+1].value= minPq[i].value;
            minPq[i].value = temp;
            
            i = 2*i+1;
        }else {
            int temp = minPq[2*i].value;
            minPq[2*i].value= minPq[i].value;
            minPq[i].value = temp;
            i = 2*i;
        }
    }

    return ret;
}

int findMinPqIndex(int id)
{
	for (int i = 1; i <= minPqPtr; i++)
		if (minPq[i].id == id) return i;

	return 0;
}

int findMaxPqIndex(int id)
{
	for (int i = 1; i <= maxPqPtr; i++)
		if (maxPq[i].id == id) return i;

	return 0;
}

void deleteFromMinPq(int n){
    int crnt = findMinPqIndex(n);
}

void pq_clear(){
    for (int i =0; i< MAXN+10;i++){
        maxPq[i].value = 0;
        maxPq[i].id = 0;
        minPq[i].value = 0;
        minPq[i].id = 0;
    }
    maxPqPtr=0;
    minPqPtr=0;
}

int main(void){
    scanf("%d", &T);

    for (int i=0; i<T; i++){
        scanf("%s", &opeartion);

        if (opeartion=='D'){
            scanf("%d", &N);
        }else {
            scanf("%d", &N);
        }

        pq_clear();
    }
}