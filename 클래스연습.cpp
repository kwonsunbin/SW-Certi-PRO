#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Student{
public:
    string name;
    int score;

    Student(string name, int score){
        this->name = name;
        this->score = score;
    }

    //bool operator < (const Student &student){
    //    return this->score < student.score; 
    //}

    //friend bool operator < (const Student &stu1, const Student &stu2){
    //    return stu1.score < stu2.score;
    //}

};

bool compare(const Student &stu1, const Student &stu2){
    return stu1.score > stu2.score;
}

int main(void){
    Student students[3] = {
        Student("김유정", 97),
        Student("윤애숙", 95),
        Student("권순빈", 100),
    };

    sort(students, students+3, compare);
    for (int i = 0; i<3; i++){
        cout << students[i].name << endl;
    }
}