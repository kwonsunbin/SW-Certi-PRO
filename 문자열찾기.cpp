#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;
string str;

int main(void){
    cin >> str;
    int ioi_ans =0;
    int koi_ans =0;
    for (int i =0; i<str.size()-2; i++){
        if (str[i] == 'K' &&  str[i+1] == 'O' && str[i+2] == 'I'){
            koi_ans ++;
        }
        if (str[i] == 'I' &&  str[i+1] == 'O' && str[i+2] == 'I' ){
            ioi_ans ++;
        }
    }

    cout << koi_ans << endl;
    cout << ioi_ans << endl;

    return 0;
}