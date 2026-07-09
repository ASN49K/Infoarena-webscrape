#include<fstream.h>
#include<string.h>
long t,i,q[3],j,k;
char a[100];
long cmmdc(long a, long b)
{
 if(b==0)
  return a;
 return cmmdc(b,a%b);
}
int main()
{
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");

 f>>t;
 f.get();
 for(i=1;i<=t;i++)
 {
  f.getline(a,100);
  j=0;
  q[0]=q[1]=0;
  for(k=0;k<strlen(a);k++)
  {
	if(a[k]==' ')
	{
	 j++;
	 k++;
	}
	q[j]*=10;
	q[j]+=a[k]-'0';
  }
  g<<cmmdc(q[0],q[1])<<'\n';
 }


 f.close();
 g.close();
 return 0;
}