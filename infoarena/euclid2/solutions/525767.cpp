#include <iostream>
using namespace std;

int cmmdc (int a,int b)
{
	int d,D=1;
	if (a>b) {d=b;
	          b=a;
	          a=d;}
	d=2;
    while (d<=a) {if (a%d==0) {a=a/d;
		                       if (b%d==0) {b=b/d;
	                                        D=D*d;}}
				  else d++;}
	return D;
}

int main (void)

{
	int T,d[200000],i;
	cin>>T;
	if (T>100000) {cout<<"nu";
	               T=0;}
	for (i=1;i<=T*2;i++)
		{cin>>d[i];
	     if ((d[i]<2)||(d[i]>2e9)) {cout<<"nu";
	                                T=0;}}
	for (i=1;i<=T*2;i=i+2)
		cout<<cmmdc(d[i],d[i+1])<<"\n";
	return 0;
}
