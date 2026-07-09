#include<iostream>
#include<fstream>
#define max(a,b) (a>b?a:b)
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short c[1025][1025],sol[1025],x[1025],y[1025];
short i,j,m,n,comt;
void lungime()
{
     for(i=1;i<=m;i++)
                      c[i][0]=0;
     for(j=0;j<=n;j++)
                      c[0][j]=0;
     for(i=1;i<=m;i++)
 {
     for(j=1;j<=n;j++)
                      if (x[i]==y[j]) c[i][j]=c[i-1][j-1]+1;
                      else  c[i][j]=max(c[i][j-1],c[i-1][j]);                          
     }
     }

void scrie(int i,int j)
{ 
     if (i==0||j==0) return;
  if (c[i][j]==c[i-1][j-1]+1) 
  {
  scrie(i-1,j-1);
  sol[++comt]=x[i];                                     
     }
  else if (c[i][j]==c[i-1][j]) scrie(i-1,j);
  else scrie(i,j-1);}
int main()
{
  
  f>>m>>n;
  for(i=1;i<=m;f>>x[i++]);
    for(j=1;j<=n;f>>y[j++]);
  f.close();
            lungime();
            scrie(m,n);
            g<<comt<<"\n";
            for(i=1;i<=comt;i++)
            g<<sol[i]<<" ";   
    g.close();
    return 0;
    
    }
