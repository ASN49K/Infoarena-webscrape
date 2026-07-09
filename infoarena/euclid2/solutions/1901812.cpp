#include<iostream>
#include<fstream>
using namespace std;
fstream fin("euclid2.in",ios::in),fout("euclid2.out",ios::out);
void cmmdc(int a,int b,int& d)
{
    if(b==0)
    {
        d=a;
        return;
    }
    cmmdc(b,a%b,d);
}


int main()
{
    int t,a,b,d,i;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        cmmdc(a,b,d);
        fout<<d<<"\n";
    }
}
