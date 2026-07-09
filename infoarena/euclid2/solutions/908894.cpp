#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a,b,r,n;

int main()
{
    fin>>n;
    for (int i=1;i<=n;i++)
    {
    fin>>a>>b;
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a<<"\n";
    }
    return 0;
}
