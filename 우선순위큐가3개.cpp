#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;

struct compare{
    bool operator()(const int &a, const int &b) const{
        if(abs(a) == abs(b)) return a < b;
        else return abs(a) < abs(b);
    }
};

multiset<int, greater<int> > maxS;
multiset<int> minS;
multiset<int, compare> absS;

int q;
int x;
int main(void){
    cin >> q;

    while(q--){
        cin >>x;
        if(x!=0){
            minS.insert(x);
            maxS.insert(x);
            absS.insert(x);
        }else {
            if (minS.empty()){
                cout << -1 << endl;
                continue;
            }
            cout << *maxS.begin() << " " << *minS.begin() << " " << *absS.begin() << endl;
            minS.erase(minS.begin());
            maxS.erase(maxS.begin());
            absS.erase(absS.begin());
        }
    }
    
}