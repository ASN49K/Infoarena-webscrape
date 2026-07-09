#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n,i,x,y;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<"\n";
    }
    return 0;
}
