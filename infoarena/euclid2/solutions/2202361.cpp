#include <iostream>
#include<fstream>
using namespace std;

ifstream fin("euclid2.in") ;
ofstream fout("euclid2.out") ;

int cmmdc(long long a, long long b)
{
    if(b==0) return a ;
     else cmmdc(b,a%b) ;
}
int main()
{
    long long n,i,x,y ;
    fin>>n ;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y ;
        fout<<cmmdc(x,y) ;
        fout<<endl ;
    }
    return 0;
}
