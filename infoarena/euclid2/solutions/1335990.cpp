#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,a,b,i;

int euclid(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else b=b-a;

    }
    return a;
}

int main()
{
    fin>>n;

    for(i=1;i<=n;++i)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }

    return 0;
}
