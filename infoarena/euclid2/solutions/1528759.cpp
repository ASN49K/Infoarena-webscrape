#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,nr;
void gcd (int a,int b)
{   if(a%b==0)
     {g<<b<<'\n';
     return;
     }
    if(b%a==0)
      {g<<a<<'\n';
      return;
      }
    if(a==b)
        {g<<a<<'\n';
        return;
        }
    int r=0;
       do
        if(a>b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        else
        {
            r=b%a;
            b=a;
            a=r;
        }
         while(r);

          g<<b<<'\n';
}
int main()
{
    f>>nr;
    for(int i=1; i<=nr; i++)
    {
        f>>a>>b;
        gcd(a,b);
    }

    return 0;
}
