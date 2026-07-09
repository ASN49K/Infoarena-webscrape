#include<fstream>
using namespace std;

fstream fin("euclid2.in", ios::in);
fstream fout("euclid2.out", ios::out);

void cmmdc(int x, int y)
{
    int r;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    fout<<x<<'\n';
    return;
}

int main()
{
    int a,b,t,i;
    fin>>t;
    for(i=1; i<=t; i++)
    {
        fin>>a>>b;
        cmmdc(a,b);
    }
    return 0;
}
