#include<fstream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int x,y,n;

int cmmdc(int x,int y)
{if(!y)return x;
 return cmmdc(y,x%y);
 }

 int main()
 { fin>>n; int i;
 for(i=1;i<=n;i++)
 {fin>>x>>y;
  fout<<cmmdc(x,y)<<'\n';
  }

  fin.close();
  fout.close();
  }

