#include<iostream.h>
#include<fstream.h>


int cmmdc(int a,int b)
{

int r;
r=a%b;
while(r!=0)
{
	a=b;
	b=r;
	r=a%b;
}
return b;
}
main()
{
	int a,b,n,i;
	ifstream f("cmmdc.in");
    ofstream g("cmmdc.out");
    f>>n; 
     for(i=1;i<=n;i++) 
	 {
	f>>a>>b;

    g<<cmmdc(a,b)<<"\n";
	 }
	f.close();
	g.close();
return 0;
}






