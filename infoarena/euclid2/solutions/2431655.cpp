#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{
    long long x,y,a,b,n,i;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        while (a != 0 && b != 0)
{
   if (a >= b)
      a %= b;
   else
      b %= a;
}
      fout<<b<<'\n';
    }
    return 0;
}
