#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t,a,b,i;
    fin>>t;
    for(i=0;i<t;i++)
    {
      fin>>a>>b;
      while(a!=b)
      {
       if(a>b)
        a=a-b;
       else
        b=b-a;
      }
      fout<<a<<"\n";
    }
    return 0;
}
