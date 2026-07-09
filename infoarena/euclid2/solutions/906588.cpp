#include <iostream>
#include <fstream>

using namespace std;

int main()
{ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,i,a,b,r;
fin>>t;
for(i=1;i<=t;i++)
    {fin>>a>>b;
     while(b)
        {r=a%b;
         a=b;
         b=r;
        }
     fout<<a<<"\n";
    }
    return 0;
}
