#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{      int r;
    while(b)
    {  r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main ()
{ int n,a,b,i;
fin>>n;
for(i=0;i<n;i++)
{   fin>>a>>b;
    fout<<cmmdc(a,b);
    fout<<"\n";
}
