#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc (int a, int b)
{
    if (a==b) return a;
    if (a>b) return cmmdc(a-b,b);
    return cmmdc (a,b-a);
}

int main()
{
    int n,a,b;
    fin>>n;
    for (int i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
