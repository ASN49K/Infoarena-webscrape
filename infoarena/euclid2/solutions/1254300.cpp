#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n ;
int  a , b;

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


int main()
{

    int i;
    fin>>n;
    for(i=1;i<=n;i++)
    {
      fin>>a>>b;
      fout<<Cmmdc(a,b);
      fout<<"\n";
     }
    return 0;
}
