#include <fstream>
#include <iostream>
using namespace std;

namespace Iterative{

  int euclid(int a,int b)
  {
    int rest;
    while(b!=0)
      {
        rest=a%b;
        a=b;
        b=rest;
      }
    return a;
  }
  
}

int main()
{
    int a,b,result,T;
    const char *FIN= "euclid2.in";
    const char *FOUT= "euclid2.out";

    ifstream fin(FIN);
    ofstream fout(FOUT);

    fin>>T;
    for(int i=1;i<=T;i++)
      {
        fin>>a>>b;
        result=Iterative::euclid(a,b);
        fout<<result<<endl;
      }
  
  

  
}