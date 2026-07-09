#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Cmmdc(int x,int y)
{
  int r;
  r=1;
  while(r>0)
   {
     r=x%y;
     x=y;
     y=r;
   }
   return x;
}

int main()
{
    int t,i,x,y;

    fin>>t;
    for(i=1; i<=t; i++)
      {
        fin>>x>>y;
        fout<<Cmmdc(x,y)<<'\n';
      }

fin.close();
fout.close();

    return 0;
}
