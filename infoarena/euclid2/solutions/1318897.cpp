#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main ()
{
    int i,T;
    int a,b,r,x,y;
    fin>>T;
    for(i=1;i<=T;i=i+1)
    {
       fin>>a>>b;
       x=a;
       y=b;
       while(y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<"\n";
    }
  fin.close();
  fout.close();
  return 0;
}

