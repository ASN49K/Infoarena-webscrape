#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc (long x, long y)
{
    long c;
    while(y!=0)
    {
        c=x%y;
        x=y;
        y=c;
    }
    return x;
}
int n,i;
long x,y;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<endl;
    }
    return 0;
}
