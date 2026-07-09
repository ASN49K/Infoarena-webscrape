#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T,a,b,r,i;
int cmmdc(int a, int b);
int main()
{
    fin>>T;
    for(i=1; i<=T; i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
int cmmdc(int a, int b)
{
    r=0;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;

    }
    return a;
}
