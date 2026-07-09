#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(long a,long b)
{ long r=1;
    while(r!=0)
    { r=a%b;
      a=b;
      b=r;
    }
    return a;
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
