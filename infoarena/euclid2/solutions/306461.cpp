#include<iostream.h>
#include<fstream.h>
int main ()
{int a, b, cmmdc, t, i;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
in>>t;
for (i=1;i<=t;i++) {
in>>a>>b;
while(a!=b) {if(a>b) a-=b;
	     if(b>a) b-=a;}
if(a==b) cmmdc=a;
	else cmmdc=0;
out<<cmmdc;         }
return 0;
}