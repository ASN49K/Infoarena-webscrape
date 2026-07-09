#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
 int n,sol,el;

int main()
{ int i,t;
    f>>t;

    for(;t;t--)
    { f>>n; sol=0;

      for(i=1;i<=n;i++)
       { f>>el; sol^=el; }

      if (sol) g<<"DA\n";
       else g<<"NU\n";
    }

    return 0;
}
