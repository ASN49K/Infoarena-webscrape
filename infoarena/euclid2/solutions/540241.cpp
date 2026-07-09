#include<iostream.h>
#include<fstream.h>
fstream f,g;
int n,a,b;

void cmmdc(int a,int b)
{
if(b==0)
   g<<a<<endl;
else
   cmmdc(b,a%b);
}

int main()
{
f.open("euclid2.in",ios::in);
g.open("euclid2.out",ios::out);
f>>n;
int i=1;
for(i=1;i<=n;i++)
	{f>>a>>b;
	cmmdc(a,b);
	}
f.close();
g.close();
return 0;
}