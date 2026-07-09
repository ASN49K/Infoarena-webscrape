#include<fstream.h>
int main()
{int a,b,T,i;
ifstream f("euclid.in");
ofstream g("euclid.out");
f>>T;
for(i=1;i<<T;i++)
{ f>>a;f>>b;
	while(a!=b)
	 {	if(a>b)
			a=a-b;
		else
			b=b-a;
	 }
  g<<b;
}
return b;
}