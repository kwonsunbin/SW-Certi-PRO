#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
int s; int e;

int main(void){
    cin >> s >> e;

    for(;;){
        if (s < 2 || s >9 || e <2 || e >9){
            cout <<  "INPUT ERROR!" << endl;
            cin >> s >> e;
        }else {
            break;
        }
    }

    if ( s<=e ){
        
            for (int j =1; j<10; j++){
                for (int i = s; i <= e; i++){
                    if (i*j <10){
                        cout << i << " * " << j << " =  " << i*j <<  "   "; 
                        continue;
                    }else {
                        cout << i << " * " << j << " = " << i*j <<  "   "; 
                    }
                }
                cout << endl;
            }
    }else { // s가 더 클 때 ?
        
            for (int j =1; j<10; j++){
                for (int i = s; i >= e; i--){
                    if (i*j <10){
                        cout << i << " * " << j << " =  " << i*j <<  "   "; 
                        continue;
                    }else {
                        cout << i << " * " << j << " = " << i*j <<  "   "; 
                    }
                }
                cout << endl;
            }
    }


    return 0;
}