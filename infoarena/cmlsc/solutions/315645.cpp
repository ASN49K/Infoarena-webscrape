# include <stdio.h>
int l[1026][1026],a[1100],b[1100],i,j,n,m,max,k,c[1100];

int main ()
{
freopen ("cmlsc.in","r",stdin);
freopen ("cmlsc.out","w",stdout);
scanf ("%i%i",&n,&m);
for (i=0;i<n;i++)
scanf ("%i",&a[i]);
for (i=0;i<m;i++)
scanf ("%i",&b[i]);
if (a[0]==b[0])
l[0][0]=1;

for (j=1;j<m;j++)
if (a[0]==b[j])
l[0][j]=1;
else
l[0][j]=l[0][j-1];


for (i=1;i<n;i++)
if (b[0]==a[i])
l[i][0]=1;
else
l[i][0]=l[i-1][0];

for (i=1;i<n;i++)
for (j=1;j<m;j++)
{
max=l[i][j-1];
if (l[i-1][j]>max)
max=l[i-1][j];
if (a[i]==b[j])
if (max<l[i-1][j-1]+1)
max=l[i-1][j-1]+1;
l[i][j]=max;
}
i=n-1;
j=m-1;
printf ("%i",l[n-1][m-1]);
printf ("\n");
while (i>=0 && j>=0)
{
if (a[i]==b[j])
{
c[k]=a[i];
k++;
i--;
j--;
}
else
if (l[i-1][j]==l[i][j])
i--;
else
j--;
}
for (i=k-1;i>=0;i--)
printf ("%i ",c[i]);

return 0;
}
