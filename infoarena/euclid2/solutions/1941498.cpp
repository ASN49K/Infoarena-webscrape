#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b,i;
int cmmdc(int a,int b)
{
    int r=0;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
