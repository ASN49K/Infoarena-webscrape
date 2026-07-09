#include<iostream.h>
#include<fstream.h>
int main()
{
int t,aux,a,b,i;
fstream f("euclid2.in",ios::in),g("euclid2.out",ios::out);
f>>t;
for(i=1;i<=t;i++)
	{
	f>>a>>b;
	g<<cmd(a,b)<<endl;
	}
int cmd(int a,int b)
	{
	if(b==0)
		return a;
	else
		cmd(b,a%b);
	}
f.close();g.close();
}