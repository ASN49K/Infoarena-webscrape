#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("flip.in");
ofstream fout("flip.out");
int T, a, b;
int GCD(int a, int b) 
{
    if(!b)
        return a;
    return GCD(b, a%b); 
}
int main()
{
    fin>>T;
    for(int i=0; i<T-1; i++)
      {
          fin>>a>>b;
          GCD(int a, int b);
          fout<<a<<"\n";
      }
    fin.close();
    fout.close();
    return 0;
}

