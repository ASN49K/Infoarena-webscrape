#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b)
{
  if(a==0)
    return b;
  return euclid(b%a,a);
}
int a,b,n;
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }
    return 0;
}
