#include<fstream.h>

#define xx 1025

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,k,a[xx],b[xx],c[xx][xx],s[xx];

int main()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
      fin>>a[i];
    for(j=1;j<=m;j++)
      fin>>b[j];
    
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        if(a[i]==b[j])
          c[i][j]=c[i-1][j-1]+1;
        else
          c[i][j]=(c[i-1][j]>c[i][j-1] ? c[i-1][j] : c[i][j-1]);
    
    for(i=n,j=m;i;)
      if(a[i]==b[j])
        s[++k]=a[i],i--,j--;
      else
      {
          if(c[i-1][j]==c[i][j])
            i--;
          else
            j--;
      }
    
    fout<<k<<'\n';
    for(i=k;i>0;i--)
     fout<<s[i]<<' ';
    
    fout.close();
    return 0;
}
