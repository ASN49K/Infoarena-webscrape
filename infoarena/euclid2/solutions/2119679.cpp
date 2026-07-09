#include <bits/stdc++.h>

using namespace std;

//ifstream in("rucsac.in");
//ofstream out("rucsac.out");

int main() {

    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int a,b,n,r;
    in>>n;
    for(int i=0;i<n;i++){
    in>>a>>b;
    while(b){
        r = a%b;
        a = b;
        b = r;
    }
    out<<a<<endl;
    }

    return 0;
}
