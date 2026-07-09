#include<iostream.h>
#include<fstream.h>
int t,i,r;long int a,b;
int main()
{
	fstream f("euclid2.in",ios::in);
	fstream g("euclid2.out",ios::out);
f>>t;
if(t<=100000&&t>=1)
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

