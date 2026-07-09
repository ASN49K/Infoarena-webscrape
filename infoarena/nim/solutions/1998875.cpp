#include <fstream>
using namespace std;
ifstream fi ("nim.in");
ofstream fo ("nim.out");
int bit[50],i,T,n,x;
void init()
{
  for (i=0;i<40;i++) bit[i]=0;
}
void completare(int nr)
{
  int k=-1;
  while (nr)
  {
    k++;
    if (nr&1) bit[k]=1-bit[k];
    nr=nr/2;
  }
}
bool verif()
{
  for (i=0;i<40;i++) if (bit[0]==1) return true;
  return false;
}
int main()
{
    fi>>T;
    while (T)
    {
      T--;
      init();
      fi>>n;
      for (i=1;i<=n;i++)
      {
        fi>>x;
        completare(x);
      }
      if (verif()) fo<<"DA"<<'\n'; else fo<<"NU"<<'\n';
    }
    return 0;
}
