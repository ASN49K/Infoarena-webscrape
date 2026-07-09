#include <fstream>
#include <math.h>
#include<iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int  n,a,b;
int euc(int a, int b)
{
    if(b)return euc(b,a%b);
    else return a;
}
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<euc(a,b);
        fout<<endl;
    }
}
