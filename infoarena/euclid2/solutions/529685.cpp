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
	 a=b;
	 b=r;
	}
	  g<<a<<"\n";
	

      
    }

f.close();
g.close();


return 0;
}
