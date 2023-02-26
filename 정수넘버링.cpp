#include <stdio.h>
#include <unordered_map>
#include <iostream>
#define MAXN ((int)2e5)

using namespace std;

int idcnt;
unordered_map<int, int> hmap;	// key , id(1~)
int S[200003];


int main(void){

    int q, key, score;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &key, &score);
		int id;
		if (hmap.count(key)) {
			id = hmap[key];
			S[id] = min(S[id], score);
		}
		else {
			hmap[key] = ++idcnt;
			id = idcnt;
			S[id] = score;
		}
		printf("%d %d\n", id, S[id]);
	}
	return 0;

}