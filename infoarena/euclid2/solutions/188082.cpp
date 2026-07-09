#include<iostream.h>
#include<fstream.h>
int main()
{
 int a,b,c,i,r;
 fstream f("euclid2.in",ios::in);
 fstream g("euclid2.out",ios::out);
 f>>T;
 for (i=1;i<=c; i++)
   {
    f>>a;f>>b;
    do
      { r=a%b;
	a=b;
	b=r;

      } while (r!=0);
	g<<a<<"\n";
      }
    g.close();
    f.close();
}
