#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    long long a,b,n,i,cmmdc,r;
    ifstream f("euclid2.in") ;
    ofstream g("euclid2.out") ;
    f >> n;
    if (n>=1 && n<=100000) {
        for (i=1;i<=n;i++) {
         f>>a;
         f>>b;
         while (b!=0 && a>=2 && b<=2*10*10*10*10*10*10*10*10*10) {
                r=a%b;
                a=b;
                b=r;}
         cmmdc=a;
         g<<cmmdc<<endl;}}
    else
         g<<"N nu este cuprins intre 1 si 100.000 . "<<endl;


    return 0;
}
