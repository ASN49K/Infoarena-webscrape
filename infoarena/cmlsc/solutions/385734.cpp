#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n;
short a[1024],b[1024];

int cmlsc()
{
  int x,y;
  int len=0;
  short sir[1024];
  x=0;
  y=0;
  int X,Y;
  X=Y=-1;
  while(x<m&&y<n)
  {
      if(a[x] == b[y]&&Y<y)
         {
          sir[len++]=a[x];
          X=x;
          Y=y;
          x++;
          y=0;
          }
       else
        (y+1)%n==0?y=0,x++:y=y+1;
      
  }  

  g << len << "\n";
  for(x=0;x<len;x++)
    g << sir[x] << " ";
  return 0;
}

  
int main()
{
  f  >> m >> n;
  int i;
  for(i=0;i<m;i++)
     f >> a[i];
  for(i=0;i<n;i++)
     f >> b[i];
  cmlsc();
  g.close();
  return 0;   
}
