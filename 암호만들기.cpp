#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int L;
int C;
vector<char> v;

bool checkMinimum(vector<char> vec){
    int vowelCount = 0;
    int consonantCount = 0;

    for(int i=0; i<vec.size(); i++){
        if ( vec[i] == 'a' | vec[i]  =='e' | vec[i] =='i' | vec[i] =='o' | vec[i] == 'u'){
            vowelCount++;
        }else {
            consonantCount++;
        }
    }
    if (vowelCount >=1 && consonantCount >=2){
        return true;
    }else {
        return false;
    }
}

//4 6
//a t c i s w
void DFS(vector<char> crnt, int s){
    if (s > C | crnt.size() > L){
        return;
    }
    if (crnt.size() == L ){
        if ( checkMinimum(crnt)){
            for (int i =0; i<L; i++){
                printf("%c", crnt[i]);
            }
            printf("\n");
        }
        return;
    }
    crnt.push_back(v[s]); //s 가 5인 경우 ?
    DFS(crnt, s+1);
    crnt.pop_back();
    DFS(crnt, s+1); // 4
}

int main(void){
    scanf("%d %d", &L, &C);
    for (int i = 0; i<C; i++){
        char temp;
        scanf(" %c", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
   // for (int i =0; i<C; i++){
   //     printf("%c", v[i]);
   // }
   // printf("\n");
    vector<char> start;
    DFS(start, 0);    

    return 0;
}