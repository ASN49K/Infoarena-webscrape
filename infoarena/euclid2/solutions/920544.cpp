#include <iostream>
#include <fstream>

using namespace std;
int t,i,a,b;
int cmmdc(int a,int b)
    {int r;
     while(b)
        {r=a%b;
         a=b;
         b=r;
        }
     return a;
    }
int main()
{ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>t;
for(i=1;i<=t;i++)
    {fin>>a>>b;

     fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
