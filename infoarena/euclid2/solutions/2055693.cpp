#include <iostream>
#include <fstream>
using namespace std;

ifstream inf("euclid2.in");
ofstream oinf("euclid2.out");
int cmmdc(int a,int b){
    if(!b) return a;
    return cmmdc(b, a%b);
}
int main()
{
    int t,a,b;
    inf>>t;
    while(t){
        inf>>a>>b;
        oinf<<cmmdc(a,b)<<"\n";
        t--;
    }
    return 0;
}
