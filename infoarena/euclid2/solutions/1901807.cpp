#include<iostream>
#include<fstream>
using namespace std;
fstream fin("euclid2.in",ios::in),fout("euclid2.out",ios::out);
int cmmdc(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}


int main()
{
    int t,a,b,i;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
}
