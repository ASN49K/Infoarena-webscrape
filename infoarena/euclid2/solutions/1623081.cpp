#include <fstream>
using namespace std;
ofstream fout("euclid2.out");
ifstream fin("euclid2.in");
int t,a,b;
int euclid(int a,int b);
int main()
{
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
}
int euclid(int a,int b)
{
    int rest=a%b;
    while(rest)
    {
        a=b;
        b=rest;
        rest=a%b;
    }
    return b;
}
