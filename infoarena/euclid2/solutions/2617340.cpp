#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Cmmdc(int x,int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{
    int i,n,x,y;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
        fout<<Cmmdc(x,y)<<endl;
    }
    return 0;
}
