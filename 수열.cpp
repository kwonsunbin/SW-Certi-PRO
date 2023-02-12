#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int cmd;
int q;
int value;
int pos;
vector<int> v;

bool compare(const int a, const int b){
    if ()
}
int main(void){

    cin >> q;

    for (int i =0; i<q; i++){
        cin >> cmd;

        if (cmd ==1){
            cin >> pos >> value;
            if (pos ==0){
                v.push_back(value);
            }else {
                v.insert(v.begin(),value);
            }

        }else if (cmd ==2){
            cin >> pos >> value;
            if (pos == 0){
                int cnt = 0;
                for (auto it = v.begin(); it != v.end(); ++it){
                    if (*it > value){
                        it = v.erase(it);
                        cnt ++;
                        if (cnt >=3){
                            break;
                        }
                    }else {
                        ++it;
                    }
                }
            }else {
                for (auto it = v.rbegin(); it != v.rend();){
                    if (*it > value){
                        it = v.erase(it);
                        cnt ++;
                        if (cnt >=3){
                            break;
                        }
                    }else {
                        ++it;
                    }
                }
            }
            
        }else if (cmd ==3){
            cin >> value ;

            sort(v.begin(), v.end(),);
        }else {
            cin >> pos >> value;

            if (pos ==0){
                for (auto it:v){
                    cout << it << ' ';
                }
            }else {
                for (auto it = v.rbegin(); it != v.rend(); ++it ){
                    cout << *it << ' ';
                }
            }

            cout << endl;
        }
    }
    return 0;
}