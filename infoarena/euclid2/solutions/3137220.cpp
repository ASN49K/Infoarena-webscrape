#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b,i;
int cmmdc(int a,int b)
{
    if(a==0 || b==0)
        return max(a,b);
    if(a>b)
        return cmmdc(a-b,b);
    return cmmdc(a,b-a);
}
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
