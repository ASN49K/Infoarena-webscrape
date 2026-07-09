#include<fstream>
using namespace std;
ifstream fin("euclid1.in");
ofstream fout("euclid1.out");
int main ()
{
    int a,b,T,i,w,x,y;
    fin>>T;
    for(i=1;i<=T;i++);
    {
          fin>>a>>b;
          x=a;
          y=b;
          while(y!=0)
          {
              w=x%y;
              x=y;
              y=w;
          }
          fout<<x<<"\n";
    }
  fin.close();
  fout.close();
    return 0;
}
