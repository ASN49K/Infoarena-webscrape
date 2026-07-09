#include<fstream>
using namespace std;

 int n,m;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");

 int main()
 {
 int k;
   f>>k;
 for(int i=1;i<=k;i++)
   {
    f>>n>>m;

   int r;
 while(m)
 {
     r=n%m;
  n=m;
  m=r;
     }
g<<n<<'\n';
   }

f.close();
g.close();
return 0;
     }
