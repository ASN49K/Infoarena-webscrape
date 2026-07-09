//BMC
#include<fstream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
    int d;
    if(a<b){ d=a; a=b; b=d; }
    while(b)
    { d=a%b;
      a=b;
      b=d; }
    return a;
}

int main()
{
    int i,t,a,b;
    fin>>t;
    for(i=1;i<=t;i++)
    { fin>>a>>b;
      fout<<cmmdc(a,b);
    }
    return 0;
}
