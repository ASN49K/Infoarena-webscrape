#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int a,b,n,r;
    in>>n;
    for(int i=0;i<n;i++){
    in>>a>>b;
    r = a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    out<<b<<endl;
    }
    out.close();
    in.close();
    return 0;
}
