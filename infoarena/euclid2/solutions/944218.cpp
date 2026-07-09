#include<fstream>
using namespace std;
int a,b,T,i;
int cmmdc(int a, int b)
{
    int r;
      while(b)
      {
          r=a%b;
          a=b;
          b=r;
      }
      return a;

}
int main ()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
