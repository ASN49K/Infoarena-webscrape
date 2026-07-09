#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }

    return a;
}

int main()
{
    int n, a1, a2;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a1>>a2;
        fout << cmmdc(a1, a2)<<endl;
    }
}