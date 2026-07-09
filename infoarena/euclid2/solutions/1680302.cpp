#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
ifstream f("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
    int r,m;
    m=a;
    if(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    if(a%m==0 && b%m==0)
        return a;

}
int main()
{
    int T, a[100],i,ok=0,j;
    f>>T;
    for(i=1; i<=T*2; i++)
    {
        f>>a[i];
    }
    for(i=1; i<=T*2; i=i+2)
    {
        fout<<cmmdc(a[i],a[i+1])<<" ";
    }



}
