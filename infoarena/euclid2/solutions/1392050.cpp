#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int euc(int a,int b)
{
    if(!b) return a;
    return euc(b,a%b);
};
int main()
{
fin>>n;
for(;n;--n)
{
    fin>>a>>b;
    fout<<euc(a,b);
}
    return 0;
}
