#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t;
long a,b;

long cmmdc(long x,long y)
{
     return(y==0 ? x : cmmdc(y,x%y));
}

int main()
{
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b);
        fout<<'\n';
    }
    
    fout.close();
    return 0;
}
