#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#define MAXN ((int)1e5)

using namespace std;

class student{
public:
    int korean;
    int english;
    int math;
    string name;

    student(int korean, int english, int math, string name){
        this->korean = korean;
        this->english = english;
        this->math = math;
        this->name = name;
    }

};

int N;
vector<student> studentVector;
int korean;
int english;
int math;
char name[11];

bool compare(const student a, const student b) {
    if (a.korean > b.korean ){
        return 1;
    }else if(a.korean == b.korean){
        if (a.english < b.english){
            return 1;
        }else if (a.english == b.english){
            if (a.math > b.math){
                return 1;
            }else if (a.math == b.math){
                if (strcmp(a.name.c_str(), b.name.c_str())<0){
                    return 1;
                }else {
                    return 0;
                }
            }else {return 0;}
        }else {return 0;}
    }else return 0;
}

int main(void){
    scanf("%d", &N);
    

    for (int i=0; i<N; i++){
        scanf("%s", &name);
        scanf("%d", &korean);
        scanf("%d", &english);
        scanf("%d", &math);
        string nameStr(name);
        studentVector.push_back(student(korean, english, math, nameStr));
    }

    sort(studentVector.begin(), studentVector.end(), compare);

    for (int i=0; i<N; i++){
        printf("%s\n", studentVector[i].name.c_str());
    }
}