#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
    if(!b)
        return a;
    else
        return cmmdc(b,a%b);
}

int main()
{
    int t,x,y;
    fin>>t;
    for(;t;t--)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
