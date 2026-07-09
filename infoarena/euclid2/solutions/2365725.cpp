#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
long a,b,r;
int t,i;
int c(long &a, long &b){
    r=0;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    in>>t;
    for(i=1;i<=t;i++){
        in>>a>>b;
        c(a,b);
        out<<a;
        out<<'\n';
    }

    return 0;
}
