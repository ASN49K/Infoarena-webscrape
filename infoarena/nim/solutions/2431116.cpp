#include <bits/stdc++.h>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n,t,nr_pietre,Xor;
int main()
{
    f>>t;
    for(int i=0;i<t;i++)
    {
      Xor=0;
      f>>n;
      for(int j=0;j<n;j++)
           {f>>nr_pietre; Xor=Xor^nr_pietre;}

      if(Xor)
        g<<"DA"<<"\n";
      else
        g<<"NU"<<"\n";
    }
    return 0;
}
