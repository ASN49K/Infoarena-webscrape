#include <fstream>
using namespace std;
int a,b,t,n,i;
int main()
{
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
       {
           f>>a>>b;
           while(b)
           {
               t=b;
               b=a%b;
               a=t;
           }
           g<<a<<"\n";
       }

    return 0;
}
