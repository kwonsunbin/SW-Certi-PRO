#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int idcnt;
unordered_map<string, int> hmap;	// key , id(1~)
int S[200003];


int main(void){

    int q, score;
    char key[23];

	scanf("%d", &q);
	while (q--) {
		scanf("%s %d", key, &score);

        for (int i=0; key[i]; i++){
            key[i] = tolower(key[i]);
        }

		int id;
		if (hmap.count(key)) {
			id = hmap[key];
			S[id] = max(S[id], score);
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