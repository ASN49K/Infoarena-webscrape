#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int a, b, c, n, i;
int cmmdc (int a, int b)
{
    int r=a%b;
    while (r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;

}
int main ()
{
   fin>>n;
   for (i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc (a,b)<<'\n';

    }
    return 0;
}
