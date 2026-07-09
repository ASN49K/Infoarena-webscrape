#include<fstream.h>
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,a,b;
f>>n;
for(i=1;i<=n;i++)
   {f>>a;f>>b;
      while (a!=b)
         {if (a>b)
         a=a-b;
       else
         if(b>a)
          b=b-a;}
    g<<a<<"\n";
    }

f.close();
g.close();


return 0;
}