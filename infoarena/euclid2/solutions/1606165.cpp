#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a,int b)
{ if(!b)
    return a;
  return cmmdc(b,a%b);
}
int main()
{ ifstream fin("euclid2.in.txt");
  ofstream fout("euclid2.out.txt");
  int T,a,b;
  fin>>T;
  for(int i=1;i<=T;i++)
     { fin>>a>>b;
       fout<<cmmdc(a,b)<<endl;
     }
  return 0;
}
