#include<fstream.h>
int main()
{
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");


 long a,t,b,i,r;
 f>>t;
 for(i=1;i<=t;i++)
 {
  f>>a>>b;
  r=a%b;
   while(r!=0)
   {
	a=b;
	b=r;
	r=a%b;
   }
   g<<b<<endl;

 }
f.close();
g.close();
return 0;


}