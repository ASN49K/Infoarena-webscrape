#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,r,i,j,k,m,l,n,w[100];
int main()
{
    fin>>n;;
    for (i=1;i<=n;i++)
    {fin>>a>>b;
    for (r=a%b;r!=0;a=b,b=r,r=a%b);
    fout<<b<<"\n";
    }
    return 0;
}
