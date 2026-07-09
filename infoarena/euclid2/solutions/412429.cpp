# include <fstream.h>
int a[1000],n,i;
ifstream f("numere.in");
ofstream g("numere.out");
 
void interclas(int i,int m,int j)
{int b[1000],x=i,k=1,y=m+1,t=i;
while(x<=m && y<=j)if (a[x]<a[y])b[k++]=a[x++];
                                         else b[k++]=a[y++];
while (x<=m)b[k++]=a[x++];
while (y<=j)  b[k++]=a[y++];
for (k=1;k<=(j-i)+1;k++)a[t++]=b[k];
}
 
void divimp(int i,int j)
{if (i<j){int m=(i+j)/2;
           divimp(i,m);
           divimp(m+1,j);
           interclas(i,m,j);}
}
 int main()
{ f>>n;
  for(i=1;i<=n;i++) f>>a[i];
  divimp(1,n);
  for(i=1;i<=n;i++)g<<a[i]<<' ';
  f.close();g.close();
  return 0;
}