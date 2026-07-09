# include <stdio.h>
long int a,b,t,i;
int div (int a,int b)
{int r;
while (a%b!=0)
{
r=a%b;
a=b;
b=r;
}
return b;
}
int main ()
{
freopen ("euclid2.in","r",stdin);
freopen ("euclid2.out","w",stdout);
scanf ("%li",&t);
for (i=0;i<t;i++)
{
scanf ("%li",&a);
scanf ("%li",&b);
printf ("%li\n",div (a,b));
}
return 0;
}