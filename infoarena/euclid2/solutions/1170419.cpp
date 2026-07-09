#include <fstream>

using namespace std;

int n,a,b;

int cmmdc(int x,int y)
{
    int r;
    r=x%y;
    while(r!=0)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}

int main()
{
    int i;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for(i=1;i<=n;++i)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }

    fin.close();
    fout.close();
    return 0;
}
