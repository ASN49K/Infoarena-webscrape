#include<fstream.h>
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,a,b,r,t;
f>>n;
for(i=1;i<=n;i++)
   {f>>a;f>>b;
   r=1;
      while (r!=0)
	{r=a%b;
         if (r!=0)
	 {a=b;
	 b=r;}
	 else
	 if (r==0)
      g<<b<<"\n";
	 }

      
    }

f.close();
g.close();


return 0;
}