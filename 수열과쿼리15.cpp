#include <stdio.h>
#define MAXN ((int)1e5)

struct Node{
    int id;
    int val;
};

bool isMin(const Node a, const Node b){
    if (a.val < b.val){
        return true;
    }else if (a.val == b.val && a.id < b.id){
        return true;
    }else {
        return false;
    }
}

int N;
int M;
Node pq[MAXN+10] ;
int hn;
int hidx[MAXN+10]; // id -> heap idx 매핑! 

void push(int val, int id){
    pq[++hn].id = id;
    pq[hn].val = val;

    hidx[id] = hn;
    for (int i = hn; i >1; i/=2){
        if (isMin(pq[i], pq[i/2])){ // i가 더 작으니 swap 한다 !
            int temp_val = pq[i].val;
            int temp_id = pq[i].id;
            pq[i].val = pq[i/2].val;
            pq[i].id = pq[i/2].id;
            pq[i/2].val = temp_val;
            pq[i/2].id = temp_id;

            hidx[pq[i/2].id] = i/2; 
            hidx[pq[i].id] = i;
        }
    }
}

void update(int i, int v){
    int idx = hidx[i];
    pq[idx].val = v;

    for (int i = idx; i >1; i/=2 ){
        if (isMin(pq[i], pq[i/2])){
            int temp_val = pq[i].val;
            int temp_id = pq[i].id;
            pq[i].val = pq[i/2].val;
            pq[i].id = pq[i/2].id;
            pq[i/2].val = temp_val;
            pq[i/2].id = temp_id;

            hidx[pq[i/2].id] = i/2; 
            hidx[pq[i].id] = i;
        }
    }

    for (int i = idx; 2*i < hn; ){
        if (isMin(pq[i], pq[i*2]) && isMin(pq[i], pq[i*2+1])){
            break;
        }else if(isMin(pq[i*2], pq[i*2+1])){
            int temp_val = pq[i].val;
            int temp_id = pq[i].id;
            pq[i].val = pq[i*2].val;
            pq[i].id = pq[i*2].id;
            pq[i*2].val = temp_val;
            pq[i*2].id = temp_id;

            hidx[pq[i].id] = i;
            hidx[pq[i*2].id] = i*2;
            i = i*2;
        }else {
            int temp_val = pq[i].val;
            int temp_id = pq[i].id;
            pq[i].val = pq[i*2+1].val;
            pq[i].id = pq[i*2+1].id;
            pq[i*2+1].val = temp_val;
            pq[i*2+1].id = temp_id;

            hidx[pq[i].id] = i;
            hidx[pq[i*2+1].id] = i*2+1;
            i = i*2+1;
        }
    }

}

void print(){
    printf("%d\n",pq[1].id);
}

int main(){
    scanf("%d", &N);

    for (int i=1; i<N+1; i++){
        int n;
        scanf("%d", &n);
        push(n, i);
    }

     scanf("%d", &M);

    for (int i=0; i<M; i++){
        int m;
        int a;
        int b;
        scanf("%d", &m);

        if (m==2){
             print();
            //printf("current state ==========\n");
            /* for(int i=1; i<=hn; i++){
                printf("id : %d, val: %d, hidx[%d]: %d \n", pq[i].id, pq[i].val, i, hidx[i]);
            } */
        }else {
            scanf("%d %d", &a, &b);
            update(a,b);
        }
    }
}

