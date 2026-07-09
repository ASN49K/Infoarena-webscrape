#include <fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t,sum,nr,i,a;

int main()
{ f>>t;
 while (t--)
 {f>>nr;
  sum=0;
  for (i=1;i<=nr;i++)
      {
          f>>a;
          sum=sum^a;
      }
  if(sum) g<<"DA";
   else g<<"NU";
    g<<'\n';
 }
    return 0;
}
