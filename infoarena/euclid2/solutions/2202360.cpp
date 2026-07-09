#include <iostream>
#include<fstream>
using namespace std;

ifstream f("euclid2.in") ;
ofstream g("euclid2.out") ;

int cmmdc(long long a, long long b)
{
    if(b==0) return a ;
     else cmmdc(b,a%b) ;
}
int main()
{
    long long n,i,x,y ;
    f>>n ;
    for(i=1;i<=n;i++)
    {
        f>>x>>y ;
        g<<cmmdc(x,y) ;
        g<<endl ;
    }
    return 0;
}
