#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
//using namespace std;
long euclid(long a,long b)
{ if(a==0) return b;
while (b!=0)
{if(a>b) a=a-b;
else b=b-a;} return a;}

   int main()
   {long t,a,b,i;
   f>>t;
   for (i=1;i<=t;i++)
    {f>>a>>b;
    g<<euclid(a,b)<<endl;}

    f.close();g.close(); return 0;
    }

