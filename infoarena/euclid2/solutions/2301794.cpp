#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i,a,b;
int cmmdc(int a, int b)
{
     int r;
     while(b!=0)
     {
          r=b;
          b=a%b;
          a=r;
     }
     return a;
}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
