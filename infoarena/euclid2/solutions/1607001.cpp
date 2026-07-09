#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(long a,long b)
{ if(!b)
    return a;
  return cmmdc(b,a%b);
}
int main()
{ ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");
  long T,a,b;
  fin>>T;
  for(int i=1;i<=T;i++)
     { fin>>a>>b;
       if(a>b)
         fout<<cmmdc(a,b)<<endl;
	   else fout<<cmmdc(b,a)<<endl;
     }
  fin.close();
  fout.close();
  return 0;
}
