#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,x,y;
int cmmdc(int x,int y)
{

    while(y!=0)
    {
        int r=x%y;

        x=y;
        y=r;
    }
    return x;
}
int main()
{
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<"\n";
    }

    return 0;
}
