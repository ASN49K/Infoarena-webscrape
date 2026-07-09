#include <fstream>

using namespace std;

int main()
{
  long a,b,r,n,i;
    fstream fi("euclid2.in",ios::in);
    fstream fo("euclid2.out",ios::out);
    fi>>n;
    for(i=1;i<=n; i++)
    {
    fi>>a>>b;
    while(a!=0)
    {
      r=a%b;
      if (r==0) { fo<<b<<endl; break; }
      a=b;
      b=r;
    }
    }
    fo.close();
    return 0;
}
