#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int gcd(int a,int b)
{return b==0? a : gcd (b, a%b);}
int main()
{int T,a,b;
fin>>T;
for(int i=0;i<2*T-3;i++)
    {fin>>a>>b;
fout<<gcd(a,b)<<endl;}

    return 0;
}
