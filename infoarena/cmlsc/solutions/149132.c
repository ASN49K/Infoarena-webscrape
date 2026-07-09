#include <stdio.h>
int a[1024],b[1024];
int x[1024][1024];
int l[1024],ll=0;
int n,m;

void push(int a)
{
l[ll]=a;
ll++;
}

int maximum(int a,int b)
{
if(a>b)return a;
return b;
}

void cit()
{
FILE *f;
int i;
f=fopen("cmlsc.in","r");
fscanf(f,"%d %d",&n,&m);
for(i=0;i<n;i++)
fscanf(f,"%d",&a[i]);

for(i=0;i<m;i++)
fscanf(f,"%d",&b[i]);

fclose(f);
}

void rez()
{
int i,j;
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
if(b[i-1]==a[j-1])
x[i][j]=1+x[i-1][j-1];
else
{
x[i][j]=maximum(x[i-1][j-1],maximum(x[i][j-1],x[i-1][j]));
}
}

void desc(int s,int p)
{
if(s)
if(p)
{
if(a[s-1]==b[p-1])
{
//        printf("%d ",a[s-1]);
        push(a[s-1]);
        desc(s-1,p-1);
        return;
}

if(x[p-1][s]>x[p][s-1])
        {
        desc(s,p-1);
        return;
        }

if(x[p-1][s]<x[p][s-1])
        {
        desc(s-1,p);
        return;
        }
desc(s,p-1);
return;
}
return;
}

void tip()
{
FILE *f;
f=fopen("cmlsc.out","w");
fprintf(f,"%d\n",ll);
int i;
for(i=ll-1;i>0;i--)
fprintf(f,"%d ",l[i]);
fprintf(f,"%d\n",l[0]);
fclose(f);
}

int main()
{
cit();
rez();
desc(n,m);
tip();
return 0;
}
