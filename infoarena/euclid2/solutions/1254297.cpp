#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n , a[100000],b[100000];

int Cmmdc(int a , int b)
{
    int r;

    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void Citire()
{
    int i;
    fin>>n;
    for(i=1;i<=n;i++)
     fin>>a[i]>>b[i];
}

int main()
{
    Citire();
    int i;
    for(i=1;i<=n;i++)
     {fout<<Cmmdc(a[i],b[i]);
      fout<<"\n";
     }
    return 0;
}
