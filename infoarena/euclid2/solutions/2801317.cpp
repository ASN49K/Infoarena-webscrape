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
    while(n)
    {
        f>>a>>b;
        n--;
        g<<euclid(a,b);
        g<<endl;
    }
    return 0;
}
