#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euc(int a, int b){
    for(int t; b;)
        t=b, b=a%b, a=t;
    return a;
}

int t, a, b;
int main(){
    in>>t;
    while(t--){
        in>>a>>b;
        out<<euc(a,b)<<'\n';
    }
    return 0;
}
