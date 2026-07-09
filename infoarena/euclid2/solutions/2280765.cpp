#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a,int b)
{
    int x,y;
    x=a,y=b;
    while(x!=0)
    {
     if(x>y)x=x-y;
     else y=y-x;
    }
    return x;
}
int main ()
{
  int T,i,a,b,z;
  fin>>T;
  for(i=1;i<=T;i=i++)
   {
    fin>>a>>b;
    z=cmmdc(a,b);
    fout<<z<<"\n";
   }
   fout.close();
   fin.close();
   return 0;
}
