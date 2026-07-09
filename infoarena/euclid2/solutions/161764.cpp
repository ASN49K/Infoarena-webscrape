#include<fstream.h>
#include<stdlib.h>
int main()
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long n,a,b,d,i,min;
fin>>n;
 for(i=1;i<=n;i++)
  {
   fin>>a>>b;
    if(a<=b)
     min=a;
      else
       min=b;
     d=min;
    while(d>=1)
      {
       if(a%d==0 && b%d==0)
	{
	fout<<d<<"\n";
	break;
	}
      d--;
      }
  }
fin.close();
fout.close();
return 0;
}