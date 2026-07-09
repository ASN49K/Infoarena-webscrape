#include <bits/stdc++.h>
using namespace std;

int cmmdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void){
    ofstream cout("euclid2.out");
    ifstream cin("euclid2.in");
    int T,x,y;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> x >> y;
        cout << cmmdc(x,y) << endl;
    }
}