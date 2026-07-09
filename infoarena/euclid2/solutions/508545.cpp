#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,c,d,i,n,r;
int main()
{   f>>n;
    for(i=1;i<=n;i++)
    {
      f>>a>>b;
      r=a%b;
      while(r!=0)
      {
        r=a%b;
        a=b;
        if(r!=0) b=r;
      }
      g<<b<<endl;
    }
    f.close();g.close();
    return 0;
}
