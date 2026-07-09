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
	ifstream f("euclid2.in");
    ofstream g("euclid2.out");
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






