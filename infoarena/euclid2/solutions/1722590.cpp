#include<iostream>
#include<fstream>
using namespace std;
fstream fin("euclid2.in",ios::in),fout("euclid2.out",ios::out);
int main()
{
    int n,i,a,b,c;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        fout<<a<<"\n";
    }
}
