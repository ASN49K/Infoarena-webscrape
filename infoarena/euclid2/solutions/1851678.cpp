#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Cmmdc(int a,int b)
{
    int r;

  r=a%b;
  while(r>0)
   {
     a=b;
     b=r;
     r=a%b;
   }
   return b;
}

int main()
{
    int t,i,a,b;

    fin>>t;
    for(i=1; i<=t; i++)
      {
        fin>>a>>b;
        fout<<Cmmdc(a,b)<<'\n';
      }

fin.close();
fout.close();

    return 0;

}
