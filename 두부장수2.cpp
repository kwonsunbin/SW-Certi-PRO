#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<int, int> m;   

void add(int worth, int cnt) {
    m[worth] += cnt;
    printf("%d\n", m[worth]);
}

void remove(int worth, int cnt) { // 2, 1, 2
    auto it = m.find(worth);         
    if (it != m.end()) {
        if (it->second <= cnt){
            m.erase(it);  
            printf("0\n");
            return;
        }
        m[worth] -= cnt;
        cout << m[worth] << endl;
    }
    else printf("0\n");
}

void sell(int flag, int cnt) {
    long long result = 0;
    while(cnt && m.size()){
        auto it = flag? --m.end() : m.begin();
        int c = min(cnt, it->second);
        result += (long long) c*it->first;
        cnt -=c;
        it -> second -= c;
        if(it->second == 0) m.erase(it);
    }
    cout << result << endl;
}

int main() {
    int q, cmd, x, cnt;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d", &cmd, &x, &cnt);
        if (cmd == 1) add(x,cnt);
        else if (cmd == 2) remove(x,cnt);
        else sell(x,cnt);
    }
    return 0;
}