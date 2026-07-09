#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,aux,t,i;
int main()
{
   f>>t;
   for(i=1;i<=t;i++)
   {
    f>>a>>b;
    while(b)
      {
       aux=a%b;
       a=b;
       b=aux;
      }
    g<<a<<'\n';
   }
    f.close();g.close();
    return 0;
}
