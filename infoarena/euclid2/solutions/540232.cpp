#include<iostream.h>
#include<fstream.h>
fstream f,g;
int n,a,b;

int cmmdc(int a,int b)
{if(b==0)
	g<<a<<endl;
 else
	cmmdc(b,a%b);
}

int main()
{
f.open("euclid2.in",ios::in);
g.open("euclid2.out",ios::out);
f>>n;
for(;n;n--)
	{f>>a>>b;
	cmmdc(a,b);
	}
f.close();
g.close();
return 0;
}