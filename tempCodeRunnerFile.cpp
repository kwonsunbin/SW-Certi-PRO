
int hidx[MAXN+10]; // id -> heap idx 매핑! 

void push(int n, int idx){
    Node node = Node(idx,n);
    pq[++hn] = node;
    hidx[idx] = hn;