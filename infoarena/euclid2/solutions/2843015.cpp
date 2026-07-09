#include <bits/stdc++.h>
using namespace std;

int main(void){
    ofstream cout("euclid2.out");
    ifstream cin("euclid2.in");
    int T,x,y;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> x >> y;
        while(y != 0){
            int r = x % y;
            x = y;
            y = r;
        }
        cout << x << endl;
    }
}