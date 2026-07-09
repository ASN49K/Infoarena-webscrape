#include<fstream.h>
int cmmdc(int x, int y)
{ int r=x%y;
  while(r!=0)
       {
       x=y;
       y=r;
       r=x%y;
       }
  return y;
}
int main()
{
  ifstream in("euclid2.in");
  ofstream out("euclid2.out");
  int n, i, x, y, z;
  in>>n;
  for(i=1;i<=n;i++)
	{  in>>x; in>>y;
	   z=cmmdc(x,y);
	   out<<z<<"\n";
	}
  out.close();
  return 0;
}
