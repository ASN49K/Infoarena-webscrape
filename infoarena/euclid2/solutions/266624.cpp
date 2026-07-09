#include<fstream.h>
int main()
{
 int n,a,b,i;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>n;
 for(i=1;i<=n;i++)
  {
   f>>a>>b;
   while(a!=b)
    if(a>b)a-=b;
    else b-=a;
   g<<a<<"\n";
   }
 f.close ();
 g.close ();
 return 0;
 }