#include <fstream.h>


ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,x[1025],y[1025],c[1025][1025];


int citire()
{
    f>>n>>m;
    int i;
    for (i=1;i<=n;i++)
       f>>x[i];
    for (i=1;i<=m;i++)
       f>>y[i];
}


void LCS()
{

     int i,j;
     for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
          if (x[i]==y[j])
            c[i][j]=c[i-1][j-1]+1;
          else
            if (c[i-1][j]>=c[i][j-1])
              c[i][j]=c[i-1][j];
            else
              c[i][j]=c[i][j-1];
            
 
}

int sol[1025];

void traseu()
{
    int i,j,max,nr=0;
    max=c[n][m];
    for (i=n;i>=1;i--)
      for (j=m;j>=1;j--)
        if (c[i][j]==max && (c[i-1][j]!=max && c[i][j-1]!=max))
          {
            nr++;
            sol[nr]=x[i];
            max--;
          }
    for (i=nr;i>=1;i--)
      g<<sol[i]<<" ";
}


int main()
{
    
    citire();
    LCS();
    g<<c[n][m]<<"\n";
    traseu();
    return 0;                                                                                                                                             
}
