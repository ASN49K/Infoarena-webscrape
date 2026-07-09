#include<iostream.h>
#include<fstream.h>
fstream f,g;
int n,a,b,c;

int cmmdc(int a,int b)
{
if(b==0)
   return a;
return cmmdc(b,a%b);
}

int main()
{
f.open("euclid2.in",ios::in);
g.open("euclid2.out",ios::out);
f>>n;
int i;
for(i=1;i<=n;i++)
	{f>>a>>b;
	c=cmmdc(a,b);
	g<<c<<endl;
	}
f.close();
g.close();
return 0;
}