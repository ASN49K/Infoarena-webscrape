#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n;

int CMMDC(int a, int b)
{
    int r;
    while (b!=0)
        {
         r=a%b;
         a=b;
         b=r;
        }
    return a;
}

void Citire()
{
    int i,a,b;
    fin>>n;
    for (i=1; i<=n; i++)
        {
         fin>>a>>b;
         fout<<CMMDC(a,b)<<"\n";
        }
}

int main()
{
    Citire();
    fin.close();
    fout.close();
    return 0;
}
