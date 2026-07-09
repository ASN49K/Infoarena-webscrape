#include<iostream.h>
#include<fstream.h>
int t,i,a,r,b;
int main()
{
	fstream f("euclid2.in",ios::in);
	fstream g("euclid2.out",ios::out);
f>>t;
for(i=1;i<=t;i++)
{
	f>>a>>b;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;}
	g<<a<<endl;
}
f.close();g.close();
return 0;
}

