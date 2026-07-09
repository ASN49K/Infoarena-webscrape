#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a,int b)
{
    int r;
    r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
long long int r,a,b,i;
fin>>r;
for(i=1;i<=r;i++)
{
    fin>>a>>b;
    fout<<cmmdc(a,b)<<'\n';
}
fin.close();
fout.close();
return 0;
}
