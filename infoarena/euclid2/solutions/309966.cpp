#include<fstream.h>
#include<iostream.h>
int a,b,n,c;
int euclid(int a, int b)
  {

   while (b) {
   c = a % b;
       a = b;
       b = c;
   }
   return a;
}
int main()
{
ifstream f("euclid2.in") ;
ofstream g("euclid2.out");
f>>n;
for(int i=1;i<=n;i++)
{f>>a>>b;

	g<<euclid(a,b);g<<endl;   }

g.close();
f.close();
return 0;
}