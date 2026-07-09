#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i,A,B;
int cmmdc(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>A>>B;
        fout<<cmmdc(A,B)<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
