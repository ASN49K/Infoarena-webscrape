#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,r,n,i;
int cmmdc (int a, int b)
{
    if (b==0)
        return a;
    else return cmmdc(b,a%b);
}
int main()
{
    fin>>n;
for (i=1;i<=n;i++)
   {fin>>a>>b;
   fout<<cmmdc(a,b);
   fout<<endl;}

    return 0;
}
