#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int aux,a,n,b,i,r;
int main()
{
   f>>n;
   for(i=1;i<=n;++i)
   {f>>a>>b;
   if(a<b)
   { aux=a;
   a=b;
   b=aux;
   }
   r=a%b;
   while(r>0)
   { a=b;
    b=r;
     r=a%b;
   }
    g<<b<<'\n';
   }

    return 0;
}
