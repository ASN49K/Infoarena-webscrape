/*#include<iostream.h>
#include<fstream.h>
fstream f,g;
int n,a,b,c;

int cmmdc(int a,int b)
{
  if(!b) return a;
return cmmdc(b,a%b);
}

int main()
{
f.open("euclid2.in",ios::in);
g.open("euclid2.out",ios::out);
f>>n;
while(n!=0)
	{n--;
	f>>a>>b;
	g<<cmmdc(a,b)<<endl;}
f.close();
g.close();
return 0;
}*/
#include <stdio.h>
#include<iostream.h>
#include<fstream.h>
int T, A, B;
fstream f,g;

int gcd(int a, int b)
{
if (!b) return a;
return gcd(b, a % b);
}

int main(void)
{
f.open("euclid2.in",ios::in);
g.open("euclid2.out",ios::out);
//freopen("euclid2.in", "r", stdin);
//freopen("euclid2.out", "w", stdout);
f>>T;
for (; T; --T)
{
f>>A>>B;
g<<gcd(A, B)<<endl;
}       
return 0;
}