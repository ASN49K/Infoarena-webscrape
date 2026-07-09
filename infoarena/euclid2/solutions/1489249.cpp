#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void cmmdc(int a, int b)
{
    int r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    fout<<b<<"\n";
}
int main()
{
    int n,x,y;
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>x>>y;
        cmmdc(x,y);
    }
    return 0;
}
