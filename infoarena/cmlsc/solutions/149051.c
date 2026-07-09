#include <stdio.h>
#define input "cmlsc.in"
#define output "cmlsc.out"
#define nmax 1025
int n1,n2,a[nmax],b[nmax],lung=0,s[nmax],d[nmax][nmax];
void citire()
{
 int i;
 FILE *fin=fopen(input,"r");
 fscanf(fin,"%d %d",&n1,&n2);
 for (i=1;i<=n1;i++) fscanf(fin,"%d",&a[i]);
 for (i=1;i<=n2;i++) fscanf(fin,"%d",&b[i]);
 fclose(fin);
}
int maxim(int a,int b)
{
 if (a>b) return a;
 return b;
}
void solve()
{
 int i,j;
 for (i=1;i<=n1;i++)
     for (j=1;j<=n2;j++)
	 if (a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
	    else d[i][j]=maxim(d[i][j-1],d[i-1][j]);
 i=n1;
 j=n2;
 while (i && j)
       if (a[i]==b[j])
	       {
		lung++;
		s[lung]=a[i];
		i--; j--;
	       }
	  else
       if (d[i-1][j]>d[i][j-1]) i--;
			   else j--;
}
void write()
{
 int i;
 FILE *fout=fopen(output,"w");
 fprintf(fout,"%d\n",lung);
 for (i=lung;i;i--)
     fprintf(fout,"%d ",s[i]);
 fclose(fout);
}
int main()
{
 citire();
 solve();
 write();
 return 0;
}