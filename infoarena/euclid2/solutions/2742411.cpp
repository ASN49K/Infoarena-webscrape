#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Cmmdc(int a,int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int n,i,a,b;
    fin>>n;
    for(i=1;i<=n;i++)
    {
      fin>>a>>b;
      fout<<Cmmdc(a,b)<<endl;
    }

    return 0;
}
