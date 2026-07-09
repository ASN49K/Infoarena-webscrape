#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
using namespace std;
long euclid(long a,long b)
{long x;
while(b!=0)
 {x=b;
 b=a%b;
 a=x;}
 return a;}

   int main()
   {long t,a,b;
   f>>t;
   for (int i=1;i<=t;i++)
    {f>>a>>b;
    g<<euclid(a,b)<<endl;}

    f.close();g.close(); return 0;
    }

