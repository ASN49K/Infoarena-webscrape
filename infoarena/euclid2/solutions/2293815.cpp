#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


unsigned euclid(unsigned a, unsigned b)
{
    if(b==0)
        return a;
    return euclid(b,a%b);
}
int n,i,a,b;

int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    return 0;
}