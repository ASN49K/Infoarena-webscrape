#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int cmmdc(int a,int b)
{
    int r=0;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main ()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b);
    }
    return 0;
}
