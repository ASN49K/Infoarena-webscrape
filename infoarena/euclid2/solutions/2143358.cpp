#include <fstream>

using namespace std;
ifstream f("fibo4.in");
ofstream g("fibo4.out");
int n,a,b;
int cmmdc(int x,int y)
{
  if(y==0)
  return x;
  return cmmdc(y, x%y);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
