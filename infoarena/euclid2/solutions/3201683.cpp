#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc(int a, int b)
{
    while(b)
    {
        int r = a % b;
        a=b;
        b=r;
    }
    return a;
}
int main ()
{
    int n;
    fin >> n;
    int x,y;
    for(int i = 1; i<=n; ++i)
    {
        fin >> x >> y;
        fout << cmmdc(x,y) << '\n';
    }
}