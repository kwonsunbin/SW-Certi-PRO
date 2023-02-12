#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN ((int)1e2)

using namespace std;
int n;
char arr[MAXN+10][MAXN+10];

int main(void){
    cin >> n;
    char crntAlphabet = 'A';
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            arr[j][i] = crntAlphabet;
            crntAlphabet++;

            if (crntAlphabet > 'Z'){
                crntAlphabet = 'A';
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}