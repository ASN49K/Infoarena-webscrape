#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,x,y,a,b;
int main()
{
   f >> n;
   for (i=1;i<=n;i++)
   {
    f >> x >> y;
    a=x;
    b=y;
    while (a!=b)
   {
       if (a>b)
        a=a-b;
       else
        b=b-a;
   }
   g << a << "\n";
   }
    return 0;
}
