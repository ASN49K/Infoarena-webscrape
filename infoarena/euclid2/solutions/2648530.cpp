#include<fstream>
using namespace std;
long long n,x,y;
long long cmmdc(long long d,long long i)
{
  int c,r;
  c=d/i;
  r=d%i;
  if(r==0)
    return i;
  return cmmdc(i,r);

}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        if(x>y)
             g<<cmmdc(x,y)<<endl;
           else
             g<<cmmdc(y,x)<<endl;


    }
    f.close();
    g.close();
    return 0;
}
