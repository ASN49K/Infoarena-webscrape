#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,n1,n2,d,i;
void euclid(int a,int &b)
{
    int r=0;
    if(a<b){r=a;a=b;b=r;}
    r=a%b;
    if(r==1)b=r;
    while(r>1)
    {
        a=b;
        b=r;
        r=a%b;
    }
}
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>n1>>n2;
        euclid(n1,n2);
        fout<<n2<<'\n';
    }
    return 0;
}
