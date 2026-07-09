#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b)
{
    if(b==0)
        {
            return a;
        }else
        {
            return cmmdc(b,a%b);
        }
}
int main()
{
    int n,a,b;
  f>>n;
  while(n)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
        n--;
    }
f.close();
g.close();
    return 0;
}
