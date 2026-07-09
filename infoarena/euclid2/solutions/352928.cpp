#include<fstream.h>
using namespace std;

unsigned long cmmdc(unsigned long a, unsigned long b)
  {
	  if(b==0) return a;
	  else return cmmdc(b,a%b);
  }

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	unsigned long T,a,b,i;
	scanf("%ld",&T);
	for(i=1; i<=T;i++)
	{
		scanf("%ld%ld",&a,&b);
		printf("%ld\n",cmmdc(a,b));
	}


}
		
	