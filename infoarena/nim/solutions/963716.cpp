#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t, s, k, i, j, nr;

    f>>t;

    for(i=1;i<=t;i++)  {

    s=0;
    f>>k;

      for(j=1;j<=k;j++)  {f>>nr; s^=nr;}

      if(!s) g<<"NU";
      else g<<"DA";
      g<<'\n';

    }

    f.close();
    g.close();
    return 0;

}
