#include <fstream>
using namespace std;
ifstream  fin ("euclid2.in");
ofstream  fout ("euclid2.out");

int cmmdc(int a,int b)
{
int x,y,r;
  x=a;
  y=b;
  while(y!=0){
    r=x%y;
    x=y;
    y=r;
  }

  return x;
}
int main()
{
    int T,i,a,b,z;
   fin>>T;
   for(i=1;i<=T;i=i+1)
  {
      fin>>a>>b;
      z=cmmdc(a,b);
      fout<<z<<"\n";
  }
  fout.close();
  fin .close();
  return 0;
}
