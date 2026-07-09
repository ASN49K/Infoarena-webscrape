#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

long long n,a,b;

int cmmdc(int a, int b){
    int c;
    do{
        c=a%b;
        a=b;
        b=c;
    }while(b);
    return a;
}


int main() {
    in>>n;
    while(n--){
        in>>a>>b;
        out<<cmmdc(a,b)<<endl;
    }
    return 0;
}
