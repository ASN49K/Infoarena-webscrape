#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GCD(int A, int B)
{
    if(!B)
        return A;
    return GCD(B, A%B);
}

int main()
{
    int T,v[100001],i,j,a,b,cmmdc;
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>a>>b;
        GCD(a,b);
        fout<<'\n';
    }
    return 0;
}
