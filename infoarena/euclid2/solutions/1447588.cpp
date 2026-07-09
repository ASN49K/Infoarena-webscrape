#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int CMMDC(int a, int b)
{int r=a%b;
 while(r!=0)
   {a=b; b=r;
    r=a%b;
   }
 return b;
}
int main()
{int T, a, b, i;
 fin>>T;
 for(i=1; i<=T; i++)
     {fin>>a>>b;
      fout<<CMMDC(a, b)<<"\n";
     }

 return 0;
}
