#include<fstream.h>
#include<stdlib.h>
int main()
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long n,a,b,r,i;
fin>>n;
 for(i=1;i<=n;i++)
  {
   fin>>a>>b;
   r=a%b;
    while(r!=0)
     {
      a=b;
      b=r;
      r=a%b;
     }
    fout<<b<<"\n";
  }
fin.close();
fout.close();
return 0;
}