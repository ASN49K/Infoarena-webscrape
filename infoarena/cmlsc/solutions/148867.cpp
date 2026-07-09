#include <fstream.h>

#define Nmax 1026

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,x[Nmax],y[Nmax],c[Nmax][Nmax];


int citire()
{
    f>>n>>m;
    int i;
    for (i=1;i<=n;i++)
       f>>x[i];
    for (i=1;i<=m;i++)
       f>>y[i];
}

int drum[Nmax][Nmax];

void LCS()
{

     int i,j;
     for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
          if (x[i]==y[j])
            {
            drum[i][j]=3;
            c[i][j]=c[i-1][j-1]+1;
            }
          else
            if (c[i-1][j]>=c[i][j-1])
              {
              drum[i][j]=2;
              c[i][j]=c[i-1][j];
              }
            else
              {
              drum[i][j]=1;                  
              c[i][j]=c[i][j-1];
              }
 
}

void traseu(int a,int b)
{
     if (a>=1 && b>=1)
       if (drum[a][b]==1)
          traseu(a,b-1);
       else
         if (drum[a][b]==2)
            traseu(a-1,b);
         else
            {
               traseu(a-1,b-1);
               g<<x[a]<<" ";
            }
}


int main()
{
    
    citire();
    LCS();
    g<<c[n][m]<<"\n";
    traseu(n,m);
    return 0;                                                                                                                                             
}
