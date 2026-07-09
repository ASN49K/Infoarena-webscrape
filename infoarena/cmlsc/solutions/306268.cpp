#include <fstream.h>


ifstream f("cmlsc.in");
ofstream g ("cmlsc.out");

int lcs[1025][1025],x[1025],y[1025],p[1025];
int n,m;

void citeste ()
{ int i;
  f>>n;
  f>>m;
  for (i=1; i<=n; i++)
   f>>x[i];
  for (i=1; i<=m; i++)
   f>>y[i];
}

void prelucreaza ()
{ for (int k=1; k<=n; k++)
    for (int h=1; h<=m; h++)
      if (x[k]==y[h])
       lcs[k][h]=1+lcs[k-1][h-1];
       else 
        if (lcs[k-1][h]>lcs[k][h-1])
          lcs[k][h]=lcs[k-1][h];
          else 
          lcs[k][h]=lcs[k][h-1];
}

void scrie ()
{ int i,k,h;
  lcs[n][m]; g<<'\n';
  for (i=0, k=n, h=m; lcs[k][h];)
   if (x[k]==y[h])
    {p[i++]=x[k]; k--; h--; }
    else if (lcs[k][h]==lcs[k-1][h])
     k--;
     else 
     h--;
  for (k=i-1; k>=0; k--) g<<p[k]<<" ";
}

int main ()
{ citeste ();
  prelucreaza ();
  scrie ();
}
   
    