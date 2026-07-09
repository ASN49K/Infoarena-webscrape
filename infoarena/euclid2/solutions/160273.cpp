# include <stdio.h>
long int a,b,t,i;
int div (int a,int b)
{
if (a==b)
return a;
else
if (a>b)
return div (a-b,b);
else
return div (a,b-a);
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