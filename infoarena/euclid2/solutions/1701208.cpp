#include <iostream>
#include<fstream>
using namespace std;
int a,b,d;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>a>>b;
    d=1;
    int verif=1;
    if(a<=b)
    {
        if(b%a==0){fout<<a;verif=0;}
        for(int i=2;i<=a/2;++i)
        {
            if(a%i==0 && b%i==0)d=i;
        }
        if(verif==1)fout<<d;
    }
    else
    if(a>b)
    {
        if(a%b==0){fout<<b;verif=0;}
        for(int i=2;i<=b/2;++i)
        {
            if(a%i==0 && b%i==0)d=i;
        }
        if(verif==1)fout<<d;
    }
}
