#include<fstream.h>
int main ()
{
	ifstream fcin("euclid2.in");
	ofstream fcout("euclid12.out");
	int a,b,i,t,r,c,d;
	fcin>>t;
	for(i=1;i<=t;i++)
		{
	fcin>>a>>b;
	c=a;d=b;
	while(a%b!=0){r=a%b;a=b;b=r;}
	while(c%d==0){c=c/d;r=d;}
	if(r==1)r--;
	fcout<<r<<'\n';
	}
return 0;
}