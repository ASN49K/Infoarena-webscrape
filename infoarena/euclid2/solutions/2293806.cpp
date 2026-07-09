#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

struct perechi
{
    int a;
    int b;
}T[100001];

int euclid(int a, int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long n,i;

int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>T[i].a;
        fin>>T[i].b;
    }
    for(i=1;i<=n;i++)
    {
        fout<<euclid(T[i].a,T[i].b)<<endl;
    }
}