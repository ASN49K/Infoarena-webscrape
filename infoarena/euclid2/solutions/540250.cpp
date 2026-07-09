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
int T, A, B;

int gcd(int a, int b)
{
if (!b) return a;
return gcd(b, a % b);
}

int main(void)
{freopen("euclid2.in", "r", stdin);
freopen("euclid2.out", "w", stdout);
scanf("%d", &T);
for (; T; --T)
{scanf("%d %d", &A, &B);
printf("%d\n", gcd(A, B));
}       
return 0;
}