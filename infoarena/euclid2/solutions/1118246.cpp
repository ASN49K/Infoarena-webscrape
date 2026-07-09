#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
        a=a-b;
        if(b>a)
        b=b-a;
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
}
